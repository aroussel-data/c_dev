typedef struct Element Element;
struct Element
{
	int number;
	Element *next;
};

typedef struct Queue Queue;
struct Queue
{
	Element *first;
};

Queue *initialisation();
void push(Queue *queue, int number);
int pop(Queue *queue);
void display_queue(Queue *queue);
