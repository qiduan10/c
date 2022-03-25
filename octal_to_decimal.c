/*
 * Converts octal to decimal.
 *
 * Project: Homework 2
 * Author: Qi Duan
 * Email: Qi.Duan001@umb.edu
 * Date: 03/09/2021
 * Notes:
 */

#include <stdio.h>

int main(void) {
    unsigned int c, num = 0, ct = 0;

    printf("Please input a positive octal integer and end with pressing Enter:\n");

    // Read the octal string, at most 10 characters.
    while ((c = getchar()) != '\n' && 
	((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')) && ct++ < 10) {
        // Convert the input string to an value storing in int
        num = num << 3 | ((c - '0') > 7 ? (c - 'A' + 10) : (c - '0'));
    }
    // If the input is not valid, output the error message.
    if (c != '\n') {
        printf("ERROR: the input should be an octal string containing 0-7, with length less than 11!\n");
    } else {    // Output the conversion table.
        printf("i\t8^i\tdigit\tproduct\n");
        for (int i = 0; i < ct; i++) {
            printf("%u\t%u\t%u\t%u\n",
                    i,  // Position i
                    1 << (3 * i), // Get 8 ** i
                    num >> (3 * i) & 7, // Get octal digit at position i
                    (1 << (3 * i)) * (num >> (3 * i) & 7));  // Multiply 8 ** i to the octal digit at position i

	}
        // Output the decimal value
        printf("Decimal value: %d\n", num);
    }

    return 0;
}

