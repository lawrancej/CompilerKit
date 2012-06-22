/**
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
#include "CompilerKit/production.h"
#include "CompilerKit/terminal.h"
#include "CompilerKit/nonterminal.h"
#include <stdarg.h>
#define COMPILERKIT_PRODUCTION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_PRODUCTION, CompilerKitProductionPrivate))
G_DEFINE_TYPE(CompilerKitProduction, compilerkit_production, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_production_finalize (GObject* object);
static void compilerkit_production_dispose (GObject* object);

/**
 * @struct _CompilerKitProductionPrivate
 * The private fields of the CompilerKitProduction struct.
 * 
 * @see #CompilerKitProduction
 */
struct _CompilerKitProductionPrivate
{
    /** @todo Declare private members here */
    /**
     * @todo dummy is here so everything will compile by default.
     * If the class does not require private fields, search for private and remove all relevant macros, function calls, etc.
     */ 
    CompilerKitNonterminal *variable;
    GList *replacement;
};

/**
 * compilerkit_production_class_init:
 * @fn compilerkit_production_class_init
 * Initializes the CompilerKitProductionClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitProductionClass to initialize
 * @return void
 */
static void
compilerkit_production_class_init (CompilerKitProductionClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitProductionPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_production_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_production_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_production_init:
 * @fn compilerkit_production_init 
 * Initializes the CompilerKitProduction instance.
 * @pre self is not NULL.
 * @param CompilerKitProduction to initialize
 * @return void
 */
static void
compilerkit_production_init (CompilerKitProduction *self)
{
    CompilerKitProductionPrivate *priv;

    self->priv = priv = COMPILERKIT_PRODUCTION_GET_PRIVATE (self);

    priv->variable = NULL;
    priv->replacement = NULL;
}

/**
 * compilerkit_production_new:
 * @fn compilerkit_production_new
 * @memberof CompilerKitProduction
 * Construct a CompilerKitProduction instance.
 * @pre None
 * @param None
 * @return A new CompilerKitProduction struct.
 */
CompilerKitProduction* compilerkit_production_new (CompilerKitNonterminal *var, ...)
{
	va_list args;
    GObject *element;
	CompilerKitProduction *result = COMPILERKIT_PRODUCTION (g_object_new (COMPILERKIT_TYPE_PRODUCTION, NULL));

    result->priv->variable = var;
    va_start (args, var);
    
    while (element = va_arg (args, GObject *))
    {
        if (COMPILERKIT_IS_NONTERMINAL (element) || COMPILERKIT_IS_TERMINAL (element))
        {
            result->priv->replacement = g_list_prepend(result->priv->replacement, element);
        }
        g_list_reverse (result->priv->replacement);
    }
    va_end (args);
    return result;
}

/**
 * compilerkit_production_finalize:
 * @fn compilerkit_production_finalize
 * Reverse what compilerkit_production_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_production_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_production_parent_class)->finalize (object);
}

/**
 * compilerkit_production_dispose:
 * @fn compilerkit_production_dispose
 * Reverse what compilerkit_production_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_production_dispose (GObject* object)
{
    CompilerKitProduction *self = COMPILERKIT_PRODUCTION (object);
    CompilerKitProductionPrivate* priv;

    priv = COMPILERKIT_PRODUCTION_GET_PRIVATE (self);

    /** @todo Deallocate memory as necessary */
    g_object_unref (priv->variable);
    g_list_free (priv->replacement);

    G_OBJECT_CLASS (compilerkit_production_parent_class)->dispose (object);
}

CompilerKitNonterminal *compilerkit_production_get_variable (CompilerKitProduction *self)
{
    return self->priv->variable;
}

GList *compilerkit_production_get_replacement (CompilerKitProduction *self)
{
    return self->priv->replacement;
}