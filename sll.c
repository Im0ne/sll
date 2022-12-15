#include "sll.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


List list_ctor()
{
	List* tmp=malloc(sizeof(List));
	tmp->first=NULL;
	return *tmp;
}

Item *item_ctor(Object data)
{
	Item* tmp=malloc(sizeof(Item));
	tmp->data=data;
	tmp->next=NULL;
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
	Item* tmp=list->first;
	list->first=tmp->next;
	free(tmp);
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
	while(42){
		if(list->first==NULL){
			free(list->first);
			break;
		}
		else{
			list_delete_first(list);
		}
	}
}
