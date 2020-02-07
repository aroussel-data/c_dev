#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_list.h"

int main(int argc, char *argv[]){

	List *my_list = initialisation();

	insert_element(my_list, 1);
	insert_element(my_list, 2);
	insert_element(my_list, 3);
	display_list(my_list);
	insert_anywhere(my_list, 2, 7);
	display_list(my_list);
	delete_anywhere(my_list, 7);
	display_list(my_list);
	delete_list(my_list);
	display_list(my_list);

	return 0;
}


List *initialisation()
{
    List *list = malloc(sizeof(*list));
    Element *element = malloc(sizeof(*element));

    if (list == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->number = 0;
    element->next = NULL;
    list->num_nodes = 1;
    list->first = element;

    return list;
}

void insert_element(List *list, int new_number){
	Element *new_node = malloc(sizeof(*new_node));

	if (list == NULL || new_node == NULL){
		exit(EXIT_FAILURE);
	}

	new_node->number = new_number;
	new_node->next = list->first;
	list->first = new_node;	
	list->num_nodes++;
}

void delete_first(List *list){
	if (list == NULL){
		exit(EXIT_FAILURE);
	}

	if (list->first != NULL){
		Element *delete_me = list->first;

		list->first = list->first->next;
		free(delete_me);
		list->num_nodes--;
	}
}

void display_list(List *list){
	Element *current_element = list->first;

	if (list == NULL || current_element == NULL){
		exit(EXIT_FAILURE);
	}

	while(current_element != NULL){
		printf("number:%d\n", current_element->number);
		printf("counter is at: %d\n", list->num_nodes);
		current_element = current_element->next; 
	}
	printf("NULL\n\n");
}

void insert_anywhere(List *list, int reference, int new_number){
	Element *current_element = list->first;
	Element *new_node = malloc(sizeof(*new_node));
	
	if (list == NULL || current_element == NULL){
		exit(EXIT_FAILURE);
	}
	
	while(current_element->number != reference){
		current_element = current_element->next;
	}
	new_node->number = new_number;
	new_node->next = current_element->next;
	current_element->next = new_node;
	list->num_nodes++;
}

void delete_anywhere(List *list, int reference){
	Element *current_element = list->first;
	Element *prev = malloc(sizeof(*prev));

	if (list == NULL || current_element == NULL){
		exit(EXIT_FAILURE);
	}
	
	while(current_element->number != reference){
		prev = current_element;
		current_element = current_element->next;
	}
	prev->next = current_element->next;
	free(current_element);
	list->num_nodes--;
}

void delete_list(List *list){
	Element *current_element = list->first;
	Element *prev = malloc(sizeof(*prev));

	while(current_element != NULL){
		prev = current_element;
		current_element = current_element->next;
		printf("deleted:%d\n", prev->number);
		printf("next: %d\n", current_element->next);
		free(prev);
		list->num_nodes--;
	}
	current_element->next = NULL;
}
