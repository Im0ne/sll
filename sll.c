#include "sll.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


List list_ctor()
{
	List* tmp=malloc(sizeof(Item));
	return *tmp;
}

Item *item_ctor(Object data)
{
	Item* tmp_ptr=malloc(sizeof(Item));
	tmp_ptr->data.name=malloc(strlen(data.name));
	tmp_ptr->data.id=data.id;
	if(tmp_ptr->data.name==NULL){
	free(tmp_ptr);
	return NULL;
	}
	strcpy(tmp_ptr->data.name,data.name);
	tmp_ptr->next=NULL;
	return tmp_ptr;
}
 

void list_insert_first(List *list, Item *i)
{
	Item* tmp=list->first;
	while(42){
		if(list->first==NULL){
			list->first=i;
			return;
		}
		else{
			i->next=tmp;
			list->first=i;
			return;
		}
		
	}
}



bool list_empty(List *list)
{
	if(list->first==NULL){
		return true;
	}
	else{
		return false;
	}
}
 
void list_delete_first(List *list)
{
	list->first=list->first->next;
}

unsigned list_count(List *list)
{
	Item* i=list->first;
	int counter=0;
	while(42){
		if(i->next==NULL){
			return ++counter;
			}
		else{
		i=i->next;
		++counter;
		}
	}
}
 

Item *list_find_minid(List *list)
{
	Item* i=list->first;
	Item* min=i;
	while(42){
		if(i->next==NULL){
			return min;
		}
		else{
			if(i->data.id<min->data.id){
				min=i;
			}
			i=i->next;
		}
	}
		
}

Item *list_find_name(List *list, char *name)
{
	Item* i=list->first;
	while(42){
		if(i->next==NULL){
			return NULL;
		}
		else{
			if(strcmp(i->data.name,name)==0){
				return i;
			}
			i=i->next;
		}
	}
	
}

void list_dtor(List *list)
{
	Item* i=list->first;
	while(42){
		if(i->next==NULL){
			free(i);
			return;
		}
		else{
			Item* tmp=i;
			i=i->next;
			free(tmp);
		}
	}
	free(list);
}
