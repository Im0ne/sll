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
	Item* tmp=malloc(sizeof(Item));
	tmp->data=data;
	return tmp;	
}
 

void list_insert_first(List *list, Item *i)
{
	i->next=list->first;
	list->first=i;
	
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
	unsigned count=0;
	while(42){
		if(i->next==NULL){
			return count+1;
		}
		else{
			count++;
			i=i->next;
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
