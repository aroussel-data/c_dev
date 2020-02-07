typedef struct Element Element;
struct Element
{
	int number;
	Element *next;
};

typedef struct List List;
struct List
{
    	int num_nodes;
	Element *first;
};

List *initialisation();
void insert_element(List *list, int new_number);
void delete_first(List *list);
void display_list(List *list);
void insert_anywhere(List *list, int reference, int new_number);
void delete_anywhere(List *list, int index_pos);
void reset_index(List *list);
void delete_list(List *list);
