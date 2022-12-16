#include "sll.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


List list_ctor()
{
    List tmp;
    tmp.first=NULL;
    return tmp;
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
		if(i==NULL){
			return count;
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
	while(i->next!=NULL){
		if(i->data.id<min->data.id){
			min=i;
		}
		i=i->next;
	}
	return min;
}

Item *list_find_name(List *list, char *name)
{
	Item* i=list->first;
	while(i->next==NULL){		
		if(strcmp(i->data.name,name)==0){
			return i;
		}
		i=i->next;
		
	}
	return NULL;
}

void list_dtor(List *list)
{
	while(list->first!=NULL){
		list_delete_first(list);
	}
	
}
