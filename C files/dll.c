#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t *temp=(node_t*)malloc(sizeof(node_t));
    temp->data=data;
    temp->prev=temp->next=NULL;
    if(is_empty(list))
    {
        list->head=list->tail=temp;
        temp=NULL;
    }
    else
    {
        list->head->prev=temp;
        temp->next=list->head;
        list->head=temp;
        temp=NULL;
    }
	(list->size)++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t *temp=(node_t*)malloc(sizeof(node_t));
    temp->data=data;
    temp->prev=temp->next=NULL;
    if(is_empty(list))
    {
        list->head=list->tail=temp;
        temp=NULL;
    }
    else
    {
        list->tail->next=temp;
        temp->prev=list->tail;
        list->tail=temp;
        temp=NULL;
    }
	(list->size)++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
     node_t *temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->prev=temp->next=NULL;

    node_t *pres;
    pres = list->head;
    //traversing through the list
    while(pres!=NULL && pres->data!=prev)
    {
        pres = pres->next;
    }
    //adding the new node
    //if it should be added at the front
    if(pres->prev==NULL)
    {
        temp->next = pres->next;
        pres->next->prev = temp;
        pres->next = temp;
        temp->prev = pres;
        list->size++;
    }
    //if it should be added at the end
    else if(pres->next==NULL)
    {
        insert_back(list,pres->data);
    }
    //if it should be added somewhere in between
    else
    {
        temp->next = pres->next;
        pres->next->prev = temp;
        pres->next = temp;
        temp->prev = pres;
        list->size++;
    }
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(!is_empty(list))
    {
        if(list->head==list->tail)
        {
            list->head=list->tail=NULL;
        }
        else
        {
            list->head=list->head->next;
            free(list->head->prev);
            list->head->prev=NULL;
        }
		(list->size)--;
    }
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if(!is_empty(list))
    {
        if(list->head==list->tail)
        {
            list->head=list->tail=NULL;
        }
        else
        {
            list->tail=list->tail->prev;
            free(list->tail->next);
            list->tail->next=NULL;
        }
		(list->size)--; 
    }
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t *ptr=list->head;
    if(!(is_empty(list)))
    {
        while(ptr!=NULL)
        {
            if(ptr->data==data)
            {
                if(ptr->next==NULL)
                    delete_back(list);
                else if(ptr->prev==NULL)
                    delete_front(list);
                else
                {
                    ptr->prev->next=ptr->next;
                    ptr->next->prev=ptr->prev;
                    free(ptr);ptr=NULL;
                }
				(list->size)--;
                break;
            }
            ptr=ptr->next;
        }
    }
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t *temp=list->head;
    if(!(is_empty(list)))
    {
        while(temp!=NULL)
        {
            if(temp->data==data)
                break;
            temp=temp->next;
        }
		return temp;
    }
    return NULL;	
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

