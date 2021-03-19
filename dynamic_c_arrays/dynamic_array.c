/**
 * Author: Abishtu
 * A dynamiclly generated array using realloc()
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int len;
	char **stringArray;
} Array;

/**
 * Appends new elements to the array
 * uses realloc to increase size of array
 * when new elements are added
 */
void append(Array *array, char *string) {

	int counter = array->len;
	asprintf((array->stringArray + counter), "%s", string);
	counter++;
	array->stringArray = (char **) realloc(array->stringArray,
										   sizeof(char *)*(counter+1));
	array->len = counter;

}

int main(int argc, char **argv) {
	Array *array = (Array *) malloc(sizeof(Array));
	array->stringArray = (char **) malloc(sizeof(char*));
	array->len = 0;
	char *userInput = (char *) malloc(sizeof(char *) * 255);

	printf("New Array Element: ");
	while(fgets(userInput, sizeof(char *) * 255, stdin) != NULL) {
		if (strcmp(userInput, "END\n") == 0) {
			break;
		}
		printf("New Array Element: ");
		append(array, userInput);
	}
	printf("\n::OUTPUT::\n");
	for(int i = 0; i < array->len; i++) {
		printf("%s", *(array->stringArray + i));
	}
	return 0;
}