#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <encrypt.c>
#include <decrypt.c>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define NOT_2_CLAS 1
#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

int check_integer(char* str){
	
    if(strlen(str) == 0)
		return FALSE;
	if(str[0] == '-' || str[0] == '+')//explicit signal
		str++;//skip it
	while(*str)
		if(!isdigit(*(str++)))
			return FALSE;
	return TRUE;
}

int isPermutation(int arr[], int n) {
    // Check for each element from 1 to N in the array
    for(int i=1; i<=n; i++) {
        int found = FALSE;
        for(int j=0; j<n; j++) {
            if(arr[j] == i) {
                found = TRUE;
                break;
            }
        }
       
        // If any element is not found, array is not a permutation
        if(!found) {
            return FALSE;
        }
    }
   
    // All elements found, array is a permutation
    return TRUE;
}








int main(int argc, char* argv[]){
    //CLA checks
	if(!check_integer(argv[1])) 
    {
        error(2, "railcipher: Fatal Error! first command-line argument must be a valid integer");
    }
		
	if(!check_integer(argv[2]) && (atoi(argv[2]) <= 26))
    {
        error(3, "railcipher: Fatal Error! second command-line argument must be a valid integer");
    }

    // Allocate memory for the integer array
    int *key = (int *)malloc(100 * sizeof(int));

    // Check if memory allocation was successful
    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int m = atoi(argv[1]); //store m 

    // Convert command-line arguments to integers and store in the array
    for (int i = 2; i < argc; i++) {
        key[i - 2] = atoi(argv[i]);
    }

    if(!isPermutation(key, m)) 
    {
        error(4, "railcipher: Fatal error! The encryption key passed as CLAs is not valid.");
    }




    // Assuming a reasonable buffer size, adjust as needed
    int bufferSize = 100;
    char *userInput = (char *)malloc(bufferSize * sizeof(char));

    if (userInput == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while(1) {

        printf("Enter 'encrypt' 'decrypt', or 'quit': ");
        char command[20];
        scanf("%s", command);


        if (strcmp(command, "quit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit the loop and end the program
        }

        else if (strcmp(command, "encrypt") == 0) {
            printf("Enter a string: ");
            // Read a line of input from the user
            fflush (stdin);
            fgets(userInput, bufferSize, stdin); //this is the problem, not prompting the user for input

            // Remove the newline character at the end, if present
            size_t len = strlen(userInput);
            if (len > 0 && userInput[len - 1] == '\n') {
                userInput[len - 1] = '\0';
            }

            // Now userInput contains the user's input
            printf("You entered: %s\n", userInput);

            char* s = encrypt(userInput, m, key);
            printf("Encrypted string:");
            printf("%s\n", s);
        }

        else if (strcmp(command, "decrypt") == 0) {
            printf("Enter a string: ");
            // Read a line of input from the user
            fflush (stdin);
            fgets(userInput, bufferSize, stdin); //this is the problem, not prompting the user for input

            // Remove the newline character at the end, if present
            size_t len = strlen(userInput);
            if (len > 0 && userInput[len - 1] == '\n') {
                userInput[len - 1] = '\0';
            }

            // Now userInput contains the user's input
            printf("You entered: %s\n", userInput);

            char* d = decrypt(userInput, m, key);
            printf("Decrypted string:");
            printf("%s\n", d);
        }
        else {
            break;
        }

    }

    return 0;
}
