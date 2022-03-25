/*
 * Converts decimal to octal.
 *
 * Project: Homework 2
 * Author: Qi Duan
 * Email: Qi.Duan001@umb.edu
 * Date: 03/09/2021
 * Notes:
 */

#include <stdio.h>

void reverse(char *s, int begin, int end);

int main(void) {

    // Declare the necessary int variable here
    unsigned int c, num = 0, ct = 0, remainder, quotient, i;
    // Declare a char array to record the octal digits on the corresponding index
    char octal[8];

    printf("Please input a positive decimal integer and end with pressing Enter:\n");

    // Read the decimal string, at most 9 characters, since 1 << 32 = 4,294,967,296.
    while ((c = getchar()) != '\n' && c >= '0' && c <= '9' && ct++ < 9) {
        // Use variable num to receive the value
        num = num * 10 + c - '0';
    }

    // If the input is not valid, output the error message.
    if (c != '\n') {
        printf("ERROR: the input should be an integer and less than 1,000,000,000!\n");
    } else if (num == 0) {  // Output 0 directly since it doesn't need the conversion table.
        printf("Octal value: 0\n");
    } else {    // Output the conversion table
        printf("steps\tdecimal\tquotient\tremainder\toct\n");
        // Convert the decimal to the octal, output the intermediate conversion table
        for (i = 0; num > 0; i++) {
	remainder = num & 7; // The 3 least significant bits are the quotient when dividing by 8.
	quotient = num >> 3;// Shift left by 3 bits to get the quotient.
	octal[i] = remainder > 9 ? (remainder - 10 + 'A') : (remainder + '0');
	printf("%u\t%u\t%u\t%u\t%c\n",
                    i,
                    num,
                    quotient,
                    remainder,
                    octal[i]);
            num = quotient;
        }
	octal[i] = '\0';
        reverse(octal, 0, i - 1);
        // Output the octal value
        printf("Octal value: %s\n", octal);
    }

    return 0;
}

// Reverse the characters on the string s from index begin to index end.
void reverse(char *s, int begin, int end) {
    char c;

    if (begin >= end)
       return;

    c = *(s + begin);
    *(s + begin) = *(s + end);
    *(s + end) = c;

    reverse(s, ++begin, --end);
}
