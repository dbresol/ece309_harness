#include <stdio.h>   // Provides input and output functions like printf and fgets
#include <string.h>  // Provides string helper functions like strcmp, strstr, and strcspn

int main() {
    // Declare a character array (buffer) to store up to 256 characters of input
    char input[256];

    // Start an infinite loop that runs until explicitly stopped with 'break'
    while (1) {
        // Print a prompt asking the user for input
        printf("Enter text: ");

        // Read input safely from standard input (keyboard) into the buffer
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // If reading input fails or ends, exit the loop
            break;
        }

        // Strip the trailing newline character ('\n') that fgets automatically attaches
        input[strcspn(input, "\n")] = '\0';

        // Check if the user typed exact match "exit"
        if (strcmp(input, "exit") == 0) {
            // Print a farewell message
            printf("Goodbye!\n");
            // Break out of the infinite loop to finish the program
            break;
        }
        // Check if the word "hello" exists anywhere inside the input string
        else if (strstr(input, "hello") != NULL) {
            // Print the hardcoded greeting
            printf("Hello there! Hope you are having a great day!\n");
        }
        // If input is neither "exit" nor contains "hello", handle default echo
        else {
            // Echo the user's input back to them
            printf("You said: %s\n", input);
        }
    }

    // Return 0 to indicate the program executed successfully
    return 0;
}