#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student Student;
struct Student{
	char name[100];
	int age;
	int score;
};

unsigned int hash_function(char *student_name);
void insert(Student *hash_table[], Student *data);
Student* search_table(Student *hash_table[], char *name);
void print_table(Student *hash_table[]);
void delete(Student *hash_table[], Student *data);
