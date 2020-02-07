typedef struct Element Element;
struct Element
{
	int number;
	Element *next;
};

typedef struct Stack Stack;
struct Stack
{
	Element *first;
};

Stack *initialisation();
void push(Stack *stack, int number);
int pop(Stack *stack);
void display_stack(Stack *stack);
