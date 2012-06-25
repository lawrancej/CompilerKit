/*
 * Copyright (C) 2012 The CompilerKit contributors.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include "CompilerKit/visitor.h"
#include <stdio.h>
#include <glib.h>
#define COMPILERKIT_VISITOR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_VISITOR, CompilerKitVisitorPrivate))
/**
 * \page visitor Visitor class
 * 
 * In object oriented programming for single dispatch languages, visitors traverse through trees with nodes of different types.
 * Traditionally, visitor interfaces overload the method `visit`.
 * Classes that implement visitor (e.g., `PrintTree` below) override these overloaded `visit` methods to accomplish a task during tree traversal.
 * 
 *     interface Visitor {
 *         void visit (Parent parent);
 *         void visit (Leaf leaf);
 *     }
 *     abstract class Tree { // Tree node
 *         Object data;
 *         void accept (Visitor v);
 *     }
 *     class Parent extends Tree { // Parent tree node type
 *         List<Tree> children;
 *         void accept (Visitor v) { v.visit (this); } // Calls visit for this type of node
 *     }
 *     class Leaf extends Tree { // Leaf tree node type
 *         void accept (Visitor v) { v.visit (this); } // Calls visit for this type of node
 *     }
 *     class PrintTree implements Visitor { // Traverses a tree.
 *         void visit (Parent parent) { // Do this for parent nodes
 *             System.out.format ("(parent %s", data);
 *             for (Tree child : parent.children) {
 *                 child.accept (this);
 *             }
 *             System.out.print (") ");
 *         }
 *         void visit (Leaf leaf) { // Do this for leaf nodes
 *             System.out.format ("(leaf %s) ", leaf.data);
 *         }
 *     }
 * 
 * Ultimately, the visitor design pattern requires examining the type of objects at runtime.
 * Single dispatch languages like Java and C# hide this detail from the programmer.
 * In the example above, the `accept` methods for `Parent` and `Leaf` are the same: both call `v.visit(this)`.
 * Behind the scenes, the object system must look up which `visit` method to call, based on the type of `this`.
 * Likewise, `PrintTree`'s `visit` method calls `accept`.
 * The object system must determine which `accept` method to call, based on the type of each `child`: is the `child` a `Parent` or a `Leaf`?
 * 
 * C has neither methods nor overloading, nor the ability to query types at runtime.
 * However, C does have function pointers, the GObject library (which enables runtime type inspection), and hash tables (through GLib).
 *
 * To implement the visitor pattern in C, CompilerKitVisitor has a hash table that associates types (GType) with handler functions (CompilerKitVisitorFunc).
 * The hash table keys are object types (e.g., COMPILERKIT_TYPE_KLEENE_STAR), analogous to the `visit` method's parameter type.
 * The value is a function to call, analogous to a pointer to the `visit` method.
 * Calling compilerkit_visitor_register builds this hash table.
 * The compilerkit_visitor_visit function looks up the function registered for the object's type, and calls it.
 * 
 * @see #CompilerKitVisitor
 * @example visitor-demo.c
 */

G_DEFINE_TYPE(CompilerKitVisitor, compilerkit_visitor, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_visitor_finalize (GObject* object);
static void compilerkit_visitor_dispose (GObject* object);
static GObject *identity (CompilerKitVisitor *visitor, GObject *visit);

/**
 * @struct _CompilerKitVisitorPrivate
 * The private fields of the CompilerKitVisitor struct.
 * 
 * @see #CompilerKitVisitor
 */
struct _CompilerKitVisitorPrivate
{
    /** A hash table of GType -> function */
    GHashTable *visitors;
};

/**
 * compilerkit_visitor_class_init:
 * @fn compilerkit_visitor_class_init
 * Initializes the CompilerKitVisitorClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitVisitorClass to initialize
 * @return void
 */
static void
compilerkit_visitor_class_init (CompilerKitVisitorClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitVisitorPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_visitor_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_visitor_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_visitor_init:
 * @fn compilerkit_visitor_init 
 * Initializes the CompilerKitVisitor instance.
 * @pre self is not NULL.
 * @param CompilerKitVisitor to initialize
 * @return void
 */
static void
compilerkit_visitor_init (CompilerKitVisitor *self)
{
    CompilerKitVisitorPrivate *priv;

    self->priv = priv = COMPILERKIT_VISITOR_GET_PRIVATE (self);

    self->state = NULL;

    priv->visitors = g_hash_table_new (g_str_hash,g_str_equal);
}

/**
 * compilerkit_visitor_new:
 * @fn compilerkit_visitor_new
 * @memberof CompilerKitVisitor
 * Construct a CompilerKitVisitor instance.
 * @pre None
 * @param None
 * @return A new CompilerKitVisitor struct.
 */
CompilerKitVisitor *compilerkit_visitor_new (void)
{
	return COMPILERKIT_VISITOR (g_object_new (COMPILERKIT_TYPE_VISITOR, NULL));
}

/**
 * compilerkit_visitor_finalize:
 * @fn compilerkit_visitor_finalize
 * Reverse what compilerkit_visitor_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_visitor_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_visitor_parent_class)->finalize (object);
}

/**
 * compilerkit_visitor_dispose:
 * @fn compilerkit_visitor_dispose
 * Reverse what compilerkit_visitor_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_visitor_dispose (GObject* object)
{
    CompilerKitVisitor *self = COMPILERKIT_VISITOR (object);
    CompilerKitVisitorPrivate* priv;

    priv = COMPILERKIT_VISITOR_GET_PRIVATE (self);
  
    /** @todo Deallocate memory as necessary */
    g_hash_table_destroy (priv->visitors);

    G_OBJECT_CLASS (compilerkit_visitor_parent_class)->dispose (object);
}

/**
 * compilerkit_visitor_identity:
 * @fn compilerkit_visitor_identity
 * Return the visited GObject
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* A visitor.
 * @param GObject* An object to visit.
 * @return GObject* The visited object.
 */
static GObject *compilerkit_visitor_identity (CompilerKitVisitor *visitor, GObject *node)
{
    g_return_val_if_fail (visitor, NULL);
    return node;
}

/**
 * compilerkit_visitor_register:
 *
 * Associate the GType of a class with a visitor function.
 * If the visitor encounters an object with an unregistered GType, the visit function will return NULL.
 *
 * @fn compilerkit_visitor_register
 * @memberof CompilerKitVisitor
 *
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GType The type of the class to visit.
 * @param CompilerKitVisitorFunc A pointer to a visitor function for the specified type.
 * @return void
 */
void compilerkit_visitor_register (CompilerKitVisitor *self, GType the_type, CompilerKitVisitorFunc func)
{
    g_return_if_fail (self);
    g_return_if_fail (the_type);
    
    g_hash_table_insert (self->priv->visitors, (gpointer) g_type_name(the_type), func);
}

/**
 * compilerkit_visitor_register_identity:
 * @fn compilerkit_visitor_register_identity
 * @memberof CompilerKitVisitor
 * Register the visitor function that returns the visited GObject*.
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GType The type of the class to visit.
 * @return void
 */
void compilerkit_visitor_register_identity (CompilerKitVisitor *self, GType the_type)
{
    compilerkit_visitor_register (self, the_type, compilerkit_visitor_identity);
}

/**
 * compilerkit_visitor_visit:
 * @fn compilerkit_visitor_visit
 * @memberof CompilerKitVisitor
 * Visit the GObject. The function it calls depends on the GObject type.
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GObject* The object to visit.
 * @return GObject* Anything to return (can be NULL).
 */
GObject *compilerkit_visitor_visit (CompilerKitVisitor *self, GObject *obj)
{
    GType the_type;
    CompilerKitVisitorFunc func;
    
    g_return_val_if_fail (self, NULL);
    if (!obj) return NULL;

    the_type = G_OBJECT_TYPE(obj);
    func = g_hash_table_lookup (self->priv->visitors, g_type_name(the_type));

    if (func) return func (self, obj);
    return NULL;
}

/**
 * compilerkit_visitor_get_state:
 * @fn compilerkit_visitor_get_state
 * @memberof CompilerKitVisitor
 * Return a pointer to any previously-set state information.
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GObject* The object to visit.
 * @return GObject* Anything to return (can be NULL).
 */
gpointer compilerkit_visitor_get_state (CompilerKitVisitor *visitor)
{
    g_return_val_if_fail (visitor, NULL);
    
    return visitor->state;
}

/**
 * compilerkit_visitor_visit:
 * @fn compilerkit_visitor_visit
 * @memberof CompilerKitVisitor
 * Visit the GObject. The function it calls depends on the GObject type.
 * @pre CompilerKitVisitor* is not NULL.
 * @param CompilerKitVisitor* The visitor instance.
 * @param GObject* The object to visit.
 * @return GObject* Anything to return (can be NULL).
 */
void compilerkit_visitor_set_state (CompilerKitVisitor *visitor, gpointer state)
{
    g_return_if_fail (visitor);
    
    visitor->state = state;
}
