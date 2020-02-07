#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stacks.h"

int main(int argc, char *argv[]){

	Stack *my_stack = initialisation();
	push(my_stack, 1);
	push(my_stack, 2);
	push(my_stack, 3);

	display_stack(my_stack);
	printf("popping top of stack: %d\n", pop(my_stack));
	
	display_stack(my_stack);

	return 0;
}


Stack *initialisation()
{
    Stack *stack = malloc(sizeof(*stack));
    Element *element = malloc(sizeof(*element));

    if (stack == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->number = 0;
    element->next = NULL;
    stack->first = element;

    return stack;
}

void push(Stack *stack, int number){
	Element *new_element = malloc(sizeof(*new_element));

	if (stack == NULL || new_element == NULL){
		exit(EXIT_FAILURE);
	}

	new_element->number = number;
	new_element->next = stack->first;
	stack->first = new_element;	
}

int pop(Stack *stack){
	if (stack == NULL){
		exit(EXIT_FAILURE);
	}

	int result = 0;
	Element *first_element = stack->first;
	
	if (first_element != NULL){
		result = first_element->number;
		stack->first = first_element->next;
		free(first_element);
	}
	return result;
}

void display_stack(Stack *stack){
	Element *current_element = stack->first;

	if (stack == NULL || current_element == NULL){
		exit(EXIT_FAILURE);
	}

	while(current_element != NULL){
		printf("number:%d\n", current_element->number);
		current_element = current_element->next; 
	}
	printf("NULL\n\n");
}
