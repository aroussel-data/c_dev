#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hangman.h"

int main(int argc, char *argv[]){

	// pointer which will hold result of strchr, and variable for guessed character.
	char *string_pointer = NULL, *second_string_pointer = NULL, guess = 0, word[100] = {0}, stars[100] = {0};
	int index, number_guesses = 10, num_lines, i = 0;
	
	// open hangman_words doc and grab a random word to assign to word[] array.
	if (!get_word(word)){
		exit(0);
	}

	get_stars(stars, strlen(word));	

	printf("Welcome to hangman...\n");

	while(number_guesses > 0){
	
		printf("You have %d guesses remaining\n", number_guesses);

		printf("what is your guess?\n");
		guess = get_letter();

		// result of strchr goes into string_pointer and gives us location of first guessed letter if any.
		string_pointer = strchr(word, guess);

		// if it found something then string_pointer will not be NULL.
		if (string_pointer != NULL){
			
			index = (int)(string_pointer - word);

			// replace star at index with the guessed letter.
			stars[index] = guess;
		
			// second result of strchr goes into second_string_pointer and gives us location of first guessed letter if any.
			second_string_pointer = strchr(string_pointer + 1, guess);
			// if it found something then string_pointer will not be NULL
			if (second_string_pointer != NULL){
			
				index = (int)(second_string_pointer - word);
			
				stars[index] = guess;

				printf("%s\n", stars);
			}
			else {
				printf("%s\n", stars);
			}
		}
		else{
			printf("wrong guess...\n");
			number_guesses--;

		}

		// at the end of each loop we should compare ANSWER and STARS to see if they match, if so then FINISHED
		if (strcmp(word, stars) == 0){
			printf("you have guessed the word!\n");
			break;
		}		

	}

	return 0;	
}

char get_letter(){

	char character = 0;

	character = getchar();
	character = toupper(character);

	while(getchar() != '\n');

	return character;

}

int get_word(char *wordpointer){

	FILE *filepointer = NULL;
	char chr, line[255]; 
	int count_lines = 0;

	filepointer = fopen("hangman_words.txt", "r");

	if (filepointer == NULL){
		printf("unable to open file");
		return 0;
	}

	chr = getc(filepointer);

	while (chr != EOF){
		
		if (chr == '\n'){
		
			count_lines++;

		}

		chr = getc(filepointer);
	}

	int r = rand() % count_lines, i = 0;

	rewind(filepointer);

	while (r > 0)
	    {
		chr = fgetc(filepointer);
		if (chr == '\n')
		    r--;
	    }
	    fgets(wordpointer, 100, filepointer);	

	wordpointer[strlen(wordpointer) - 1] = '\0';

	fclose(filepointer);
	
	return 1;

}

int get_stars(char *stars_array, int array_length){

	int i = 0;

	for (i = 0; i < array_length; i++){
	
		stars_array[i] = '*';
	
	}

}
