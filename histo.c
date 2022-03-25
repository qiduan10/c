/*
 * Draw histogram of word lengths in the works of William Shakespeare
 *
 * Project: Homework 4
 * Author: Qi Duan
 * Email: Qi.Duan001@umb.edu
 * Date: 05/04/2021
 * Notes:
 */

#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN  1
#define MAX 28
#define BLOCK 4000

/* Check whether the character is alphanumeric */
int isAlphanumeric(char c) {
    return ('a' <= c && c <= 'z') ||
      ('A' <= c && c <= 'Z') ||
      ('0' <= c && c <= '9');
}

int main(int argc, char *argv[]) {
    int c, state = OUT, length = 0, i, j, counter[MAX];
    char word[30], longestWord[30];
    FILE *input, *output;   /* FILE pointers to open the file */

    /* Initialize the counter */
    for (i = 0; i < MAX; i++)
        counter[i] = 0;
    
    /* Open the file */
    input = fopen("complete_shakespeare.txt", "r");
    output = fopen("word_length_histogram.txt", "w");

    /* Keep reading the character in the file */
    while ((c = getc(input)) != EOF) {
        /* If the character is alphanumeric, record it */
        if (isAlphanumeric(c)) {
            word[length] = c;
	        ++length;
        }
        /* If the character is not alphanumeric, increment the corresponding counter */
        else {
            counter[length]++;
	    
	    //if longest word till now
	    if(length > state) {
            state = length;
	    }
            length = 0;
        }
    }
    /* If the file ends with a word, record its length */
    if(length > 0) {
        counter[length]++;
	if(length > state) {
        state = length;
	}
        length = 0;
    }
    fprintf(output, "/* Longest Word */");
    fprintf(output, "%s\n\n", longestWord);

    /* Make the histogram */
    for (i = 1; i < MAX; i++) {
        fprintf(output, "%2d %6d ", i, counter[i]);
        if(counter[i] > 0) {
            for(j = 0; j < counter[i] / 4000 + 1; j++)
            fprintf(output, "*");
	}
        fprintf(output, "\n");
    }

    /* Don't forget to close the FILEs */
    fclose(input);
    fclose(output);

    return 0;
}
