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
#include "CompilerKit/automata.h"
#include <glib.h>
#include <string.h>
#include "../include/CompilerKit/automata.h"

#define COMPILERKIT_FSM_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), COMPILERKIT_TYPE_FSM, CompilerKitFSMPrivate))

G_DEFINE_TYPE(CompilerKitFSM, compilerkit_FSM, G_TYPE_OBJECT);

/** Private method function prototypes */
static void compilerkit_FSM_finalize (GObject* object);
static void compilerkit_FSM_dispose (GObject* object);

/**
 * @struct _CompilerKitFSMPrivate
 * The private fields of the finite state machine.
 * 
 * @see #CompilerKitFSM
 */
struct _CompilerKitFSMPrivate
{
  CompilerKitFSMNode* start;
};

/**
 * compilerkit_FSM_finalize:
 * Reverse what compilerkit_FSM_class_init allocated.
 * @pre GObject is not NULL.
 * @param GObject to finalize
 * @return void
 */
static void
compilerkit_FSM_finalize (GObject* object)
{
	/* Reverse what was allocated by class init */
	G_OBJECT_CLASS (compilerkit_FSM_parent_class)->finalize (object);
}

/**
 * compilerkit_FSM_dispose:
 * Reverse what compilerkit_FSM_init allocated.
 * @fn compilerkit_FSM_dispose
 * @pre GObject is not NULL.
 * @param GObject to dispose.
 * @return void
 */
static void
compilerkit_FSM_dispose (GObject* object)
{
    /* Reverse what was allocated by instance init */
    CompilerKitFSM *self = COMPILERKIT_FSM (object);
    CompilerKitFSMPrivate* priv;

    priv = COMPILERKIT_FSM_GET_PRIVATE (self);

    //compilerkit_FSM_node_destroy_all(priv->start);

    G_OBJECT_CLASS (compilerkit_FSM_parent_class)->dispose (object);
}

/**
 * compilerkit_FSM_class_init:
 * Initializes the CompilerKitFSMClass struct.
 * @pre klass is not NULL.
 * @param CompilerKitFSMClass to initialize
 * @return void
 */
static void
compilerkit_FSM_class_init (CompilerKitFSMClass *klass)
{
    GObjectClass *g_object_class;

    /* Add private structure */
    g_type_class_add_private (klass, sizeof (CompilerKitFSMPrivate));

    /* Get the parent gobject class */
    g_object_class = G_OBJECT_CLASS(klass);

    /* Hook finalization functions */
    g_object_class->dispose = compilerkit_FSM_dispose;   /* instance destructor, reverse of init */
    g_object_class->finalize = compilerkit_FSM_finalize; /* class finalization, reverse of class init */
}

/**
 * compilerkit_FSM_init:
 * Initializes the CompilerKitFSM struct.
 * @pre self is not NULL.
 * @param CompilerKitFSM to initialize
 * @return void
 */
static void
compilerkit_FSM_init (CompilerKitFSM *self)
{
    CompilerKitFSMPrivate* priv;
    self->priv = priv = COMPILERKIT_FSM_GET_PRIVATE (self);

    priv->start = NULL;
}

CompilerKitFSM* compilerkit_FSM_new(gchar* start)
{
    CompilerKitFSM *result = COMPILERKIT_FSM(g_object_new(COMPILERKIT_TYPE_FSM,NULL));
    compilerkit_FSM_set_start_state(result,g_strdup(start));
    return result;
}

void compilerkit_FSM_set_start_state(CompilerKitFSM *self, gchar* id)
{
    //Make the node that has the id specified as the start point
    compilerkit_FSM_node_add(self, NULL, id, NULL);
}

gchar* compilerkit_FSM_get_start_state(CompilerKitFSM *self)
{
	if(self->priv->start == NULL)
		return NULL;
	return g_strdup(self->priv->start->id);
}

void compilerkit_FSM_add_transition(CompilerKitFSM* self, gchar* parentID, gchar* id, gchar value)
{
    compilerkit_FSM_node_add(self,parentID,id,value);
}

bool compilerkit_FSM_has_state(CompilerKitFSM* self, gchar* id)
{
	//Reset all the node visited status so we can traverse it correctly
    compilerkit_FSM_node_reset_visited(self->priv->start);
    //Grab the correct node
    CompilerKitFSMNode* node = compilerkit_FSM_node_find(self->priv->start,id);
	//if the node does exist return true
	if(node != NULL)
		return true;
	return false;
}

void compilerkit_FSM_add_end_state(CompilerKitFSM* self,gchar* id)
{
    //Reset all the node visited status so we can traverse it correctly
    compilerkit_FSM_node_reset_visited(self->priv->start);
    //Grab the correct node
    CompilerKitFSMNode* node = compilerkit_FSM_node_find(self->priv->start,id);
    if(node != NULL)
	node->endState = true;
}

bool compilerkit_FSM_is_accepting_state(CompilerKitFSM* self, gchar* id)
{
     //Reset all the node visited status so we can traverse it correctly
    compilerkit_FSM_node_reset_visited(self->priv->start);
    //Grab the correct node
    CompilerKitFSMNode* node = compilerkit_FSM_node_find(self->priv->start,id);
    if(node == NULL)
	return false;
    printf("found it son\r\n");
    return node->endState;
}

void compilerkit_FSM_node_reset_visited(CompilerKitFSMNode* node)
{
    //Check to make sure the current node is not NULL before trying to access its data
    if(node == NULL)
	return;
    //Set the nodes visited status to false
    node->visited = false;
    //Loop through all the paths the node has to make sure they are all visited
    int i = 0;
    CompilerKitFSMNode* path = NULL;
    while((path = (CompilerKitFSMNode*)g_list_nth_data(node->paths,i++)) != NULL)
	if(path->visited == false) //Make sure not to visit already visited nodes
	    compilerkit_FSM_node_reset_visited(path);
}

CompilerKitFSMNode* compilerkit_FSM_node_find(CompilerKitFSMNode* node, gchar* id)
{
    //Make sure the node is not NULL before attempting to access its private data
    if(node == NULL)
	return NULL; 
    //Check if the node is the node we are looking for. If it is return it.
    if(g_strcmp0(node->id,id) == 0)
	return node;
    node->visited = true;
    //Loop through all pathways of the current node to check if they are the node we are looking for.
    int i = 0;
    CompilerKitFSMNode* path = NULL;
    if(node->paths == NULL)
      return NULL;
    while((path = (CompilerKitFSMNode*)g_list_nth_data(node->paths,i++)) != NULL)
	{
		if(path->visited == false)
		{
			CompilerKitFSMNode* returnNode = compilerkit_FSM_node_find(path,id);
			if(g_strcmp0(returnNode->id,id) == 0)
				return returnNode;
		}
	}
	return NULL;
}

gchar* compilerkit_FSM_get_next_state(CompilerKitFSM* self, gchar* state, gchar value)
{
    CompilerKitFSMNode* node = NULL;
    compilerkit_FSM_node_reset_visited(self->priv->start);
    node = compilerkit_FSM_node_find(self->priv->start,state);
    if(node == NULL)
      return NULL;
    int i = 0;
    CompilerKitFSMNode* path = NULL;
    if(node->paths == NULL)
	return NULL;
    while((path = (CompilerKitFSMNode*)g_list_nth_data(node->paths,i++)) != NULL)
    {
	if(path->data == value)
	  return path->id;
    }
    return NULL;
}

bool compilerkit_FSM_node_add(CompilerKitFSM *self, gchar* parentID, gchar* id, gchar value)
{
    if(id == NULL)
		 return false;
    //Reset all the node visited status so we can traverse it correctly
    compilerkit_FSM_node_reset_visited(self->priv->start);
    //Make sure the node does not already exist
    if(compilerkit_FSM_node_find(self->priv->start,id) != NULL)
		return false;
    //Declare the node for the parent
    CompilerKitFSMNode* node = NULL;
    if(parentID != NULL)
    {
		//Get the node designated as the parent node
		compilerkit_FSM_node_reset_visited(self->priv->start);
		node = compilerkit_FSM_node_find(self->priv->start,parentID);
    }
    //If we have been given a parent and it was not found return a state of failure
    if(node == NULL && parentID != NULL)
		return false;
    //Allocate a new node and set the data for it
    CompilerKitFSMNode* newNode = malloc(sizeof(CompilerKitFSMNode));
    newNode->id = g_strdup(id);
    newNode->data = value;
    newNode->paths = NULL;
    newNode->endState = false;
    newNode->visited = false;
    if(node != NULL)
    {
		//Append the new node onto the parent node
		node->paths = g_list_append(node->paths,newNode);
    }
    else
    {
		//Set the new node as the start node
		self->priv->start = newNode;
    }
    //Return that the addition was complete
    return true;
}

void compilerkit_FSM_node_destroy_all(CompilerKitFSMNode* node)
{
    int i = 0;
    CompilerKitFSMNode* path = NULL;
    while((path = (CompilerKitFSMNode*)g_list_nth_data(node->paths,i++)) != NULL)
	compilerkit_FSM_node_destroy_all(path);
    //g_free(node->data);
    //g_free(node->id);
    g_list_free(node->paths);
    //g_free(node);
}