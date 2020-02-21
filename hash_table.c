#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include <time.h>

#define TABLE_LENGTH 10

int main(void) {
	Student *students[10] = {NULL};

	Student student1 = {"George R", 29, 80}, student2 = {"Gale P", 26, 90}, student3 = {"John T", 59, 80};

	insert(students, &student1);
	insert(students, &student2);
	insert(students, &student3);

	print_table(students);	

	Student *result = search_table(students, "George R");
	if (result == NULL){
		printf("Name: %s, Age: %d, Score: %d\n", NULL, NULL, NULL);
	}
	else{
		printf("Name: %s, Age: %d, Score: %d\n", result->name, result->age, result->score);
	}

	delete(students, &student3);

	print_table(students);

	return 0;
}

unsigned int hash_function(char *name){
	int i, hash_result;

	// iterate over each element in student_name array and add them to hash_result to make a final int result
	for (i = 0; name[i] != '\0'; i++){
		hash_result += name[i];
	}
	// use mod of the list length to ensure the hash result index is within the list values
	hash_result = hash_result % TABLE_LENGTH;

	return abs(hash_result);
}

void insert(Student *hash_table[], Student *data){
	if (data == NULL){
		printf("Invalid student record passed to insert\n");
	}
	else{
		int index = hash_function(data->name);
		
		if (hash_table[index] == NULL){  // if index corresponds to empty space
			printf("Inserting %s in location %d\n", data->name, index);
			hash_table[index] = data;
		}
		else{  // otherwise loop to find the empty space
			for (int i=0; i < TABLE_LENGTH; i++){
				int try = (index + i) % TABLE_LENGTH;
				if (hash_table[try] == NULL){
					printf("Inserting %s in location %d\n", data->name, try);
					hash_table[try] = data;
					break;
				}
			}
		}
	}
}

void delete(Student *hash_table[], Student *data){
	if (data == NULL){
		printf("Invalid student record passed to delete\n");
	}
	else {
	
		int index = hash_function(data->name);

		if (hash_table[index] !=NULL && hash_table[index]->name == data->name){  // if index corresponds to correct entry
			printf("Deleting %s that was in location %d\n", hash_table[index]->name, index);
			hash_table[index] = NULL;
		}
		else{  // otherwise loop to find the correct entry
			for (int i=0; i < TABLE_LENGTH; i++){
				int try = (index + i) % TABLE_LENGTH;
				if (hash_table[try] != NULL && strcmp(hash_table[try]->name, data->name) == 0){
					printf("Deleting %s that was in location %d\n", hash_table[try]->name, try);
					hash_table[try] = NULL;
				}
			}
		}
	}
}

Student* search_table(Student *hash_table[], char *name){
	int index;
	index = hash_function(name);  	
	for (int i=0; i < TABLE_LENGTH; i++){
		int try = (index + i) % TABLE_LENGTH;
		if (hash_table[try] != NULL && strcmp(hash_table[try]->name, name) == 0){
			printf("Found entry\n");
			return hash_table[try];
		}
	}
	printf("Did not find entry\n");
	return NULL;
}

void print_table(Student *hash_table[]){
	printf("---Start of hash table---\n");
	for (int i=0; i < TABLE_LENGTH; i++){
		if (hash_table[i] == NULL){
			printf("Name: %s, Age: %d, Score: %d\n", NULL, NULL, NULL);
			continue;
		}
		printf("Name: %s, Age: %d, Score: %d\n", hash_table[i]->name, hash_table[i]->age, hash_table[i]->score);
	}
	printf("---End of hash table---\n");
}

