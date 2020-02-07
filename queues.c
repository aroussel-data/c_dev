#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "queues.h"

int main(int argc, char *argv[]){

	Queue *my_queue = initialisation();
	push(my_queue, 1);
	push(my_queue, 2);
	push(my_queue, 3);

	display_queue(my_queue);
	printf("popping start of queue: %d\n", pop(my_queue));
	printf("popping start of queue: %d\n", pop(my_queue));
	display_queue(my_queue);

	return 0;
}


Queue *initialisation()
{
    Queue *queue = malloc(sizeof(*queue));
    Element *element = malloc(sizeof(*element));

    if (queue == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->number = 0;
    element->next = NULL;
    queue->first = element;

    return queue;
}

void push(Queue *queue, int number){
	Element *new_element = malloc(sizeof(*new_element));

	if (queue == NULL || new_element == NULL){
		exit(EXIT_FAILURE);
	}

	new_element->number = number;
	new_element->next = NULL;

	if (queue->first != NULL){  // queue exists
		Element *current_element = queue->first;
		while(current_element->next != NULL){
			current_element = current_element->next;
		}
		current_element->next = new_element;
	}
	else{  // queue does not exist
		queue->first = new_element;
	}
}

int pop(Queue *queue){
	if (queue == NULL){
		exit(EXIT_FAILURE);
	}

	int result = 0;
	Element *first_element = queue->first;
	
	if (first_element != NULL){
		result = first_element->number;
		queue->first = first_element->next;
		free(first_element);
	}
	return result;
}

void display_queue(Queue *queue){
	Element *current_element = queue->first;

	if (queue == NULL || current_element == NULL){
		exit(EXIT_FAILURE);
	}

	while(current_element != NULL){
		printf("number:%d\n", current_element->number);
		current_element = current_element->next; 
	}
	printf("NULL\n\n");
}
