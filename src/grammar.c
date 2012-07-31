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
#include "CompilerKit/cfg.h"
#include "CompilerKit/production.h"
#include <stdarg.h>
#define COMPILERKIT_GRAMMAR_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_GRAMMAR, CompilerKitGrammarPrivate))
G_DEFINE_TYPE(CompilerKitGrammar, compilerkit_grammar, G_TYPE_OBJECT);

/** @todo Private method function prototypes go here (for private methods, declare as static) */
static void compilerkit_grammar_finalize (GObject* object);
static void compilerkit_grammar_dispose (GObject* object);

/**
 * @struct _CompilerKitGrammarPrivate
 * The private fields of the CompilerKitGrammar struct.
 * 
 * @see #CompilerKitGrammar
 */
struct _CompilerKitGrammarPrivate
{
    /** @todo Declare private members here */
    /** The start nonterminal. */
    CompilerKitNonterminal *start;
    /** The set of productions. */
    GHashTable *productions;
};

/**
 * compilerkit_grammar_class_init:
 * @fn compilerkit_grammar_class_init
 * Initializes the CompilerKitGrammarClass (virtual table).
 * @pre klass is not NULL.
 * @param CompilerKitGrammarClass to initialize
 * @return void
 */
static void
compilerkit_grammar_class_init (CompilerKitGrammarClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitGrammarPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_grammar_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_grammar_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_grammar_init:
 * @fn compilerkit_grammar_init 
 * Initializes the CompilerKitGrammar instance.
 * @pre self is not NULL.
 * @param CompilerKitGrammar to initialize
 * @return void
 */
static void
compilerkit_grammar_init (CompilerKitGrammar *self)
{
    CompilerKitGrammarPrivate *priv;

    self->priv = priv = COMPILERKIT_GRAMMAR_GET_PRIVATE (self);

    priv->start = NULL;
    priv->productions = g_hash_table_new (NULL, NULL);
}

/**
 * compilerkit_grammar_new:
 * @fn compilerkit_grammar_new
 * Construct a CompilerKitGrammar instance.
 * @pre None
 * @param CompilerKitNonterminal* The starting nonterminal
 * @param A variable length argument list of CompilerKitProduction* terminated with a NULL pointer.
 * @return A new CompilerKitGrammar struct.
 * @memberof CompilerKitGrammar
 */
CompilerKitGrammar *compilerkit_grammar_new (CompilerKitNonterminal *start, ...)
{
	va_list args;
	CompilerKitGrammar *cfg = COMPILERKIT_GRAMMAR (g_object_new (COMPILERKIT_TYPE_GRAMMAR, NULL));
    CompilerKitProduction *production;
    GList *list = NULL;
    CompilerKitNonterminal *key;

	va_start(args,start);

    cfg->priv->start = start;
    
    while (production = va_arg(args, CompilerKitProduction*))
    {
        key = compilerkit_production_get_variable (production);
        if (list = g_hash_table_lookup (cfg->priv->productions, key))
        {
            list = g_list_append (list, production);
            g_hash_table_replace (cfg->priv->productions, key, list);
        }
        else
        {
            list = g_list_append (list, production);
            g_hash_table_insert (cfg->priv->productions, key, list);
        }
    }
    va_end (args);
    return cfg;
}

/**
 * compilerkit_grammar_finalize:
 * @fn compilerkit_grammar_finalize
 * Reverse what compilerkit_grammar_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to finalize.
 * @return void
 */
static void
compilerkit_grammar_finalize (GObject* object)
{
	G_OBJECT_CLASS (compilerkit_grammar_parent_class)->finalize (object);
}

/**
 * compilerkit_grammar_dispose:
 * @fn compilerkit_grammar_dispose
 * Reverse what compilerkit_grammar_init allocated.
 * @pre GObject is not NULL.
 * @param GObject* An object to dispose.
 * @return void
 */
static void
compilerkit_grammar_dispose (GObject* object)
{
    CompilerKitGrammar *self = COMPILERKIT_GRAMMAR (object);
    CompilerKitGrammarPrivate* priv;

    priv = COMPILERKIT_GRAMMAR_GET_PRIVATE (self);

    g_hash_table_destroy (priv->productions);
    g_object_unref (priv->start);

    G_OBJECT_CLASS (compilerkit_grammar_parent_class)->dispose (object);
}

/** @todo It'd be better for grammar to maintain a single list of productions, and for the hash to point within that list. */


/**
 * compilerkit_grammar_productions:
 * @fn compilerkit_grammar_productions
 * Return the productions for the grammar.
 * @pre CompilerKitGrammar* is not NULL.
 * @param CompilerKitGrammar* The grammar.
 * @return A list of productions for the grammar.
 * @memberof CompilerKitGrammar
 */
GList *compilerkit_grammar_productions (CompilerKitGrammar *grammar)
{
    GList *values = g_hash_table_get_values (grammar->priv->productions);
    GList *item;
    GList *result = NULL;
    
    while (values)
    {
        item = (GList *) values->data;
        while (item)
        {
            result = g_list_prepend (result, item->data);
            item = g_list_next (item);
        }
        values = g_list_next(values);
    }
    return result;
}

/**
 * compilerkit_grammar_productions_for:
 * @fn compilerkit_grammar_productions_for
 * Return the productions for a given nonterminal.
 * @pre CompilerKitGrammar* is not NULL.
 * @param CompilerKitGrammar* The grammar.
 * @param CompilerKitNonterminal* A nonterminal.
 * @return A list of productions for the given nonterminal, or NULL.
 * @memberof CompilerKitGrammar
 */
GList *compilerkit_grammar_productions_for (CompilerKitGrammar *grammar, CompilerKitNonterminal *variable)
{
    return g_hash_table_lookup (grammar->priv->productions, variable);
}

/**
 * compilerkit_grammar_nonterminals:
 * @fn compilerkit_grammar_nonterminals
 * Return a list of nonterminals in the grammar.
 * @pre CompilerKitGrammar* is not NULL.
 * @param CompilerKitGrammar* The grammar.
 * @return A list of nonterminals in the given grammar, or NULL.
 * @memberof CompilerKitGrammar
 */
GList *compilerkit_grammar_nonterminals (CompilerKitGrammar *grammar)
{
    return g_hash_table_get_keys (grammar->priv->productions);
}

/**
 * compilerkit_grammar_get_start:
 * @fn compilerkit_grammar_get_start
 * Return the starting nonterminal.
 * @pre CompilerKitGrammar* is not NULL.
 * @param CompilerKitGrammar* The grammar.
 * @return The starting nonterminal.
 * @memberof CompilerKitGrammar
 */
CompilerKitNonterminal *compilerkit_grammar_get_start (CompilerKitGrammar *grammar)
{
    return grammar->priv->start;
}
