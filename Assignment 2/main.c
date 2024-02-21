#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <encrypt.c>
#include <math.h>

int main(int argc, char* argv[]){

    char string[] = "Hello World";
    int l = strlen(string); //testing strlen function

    // temporary hardcoded key array
    //int key = {4,3,1,2,5,6,7};

    // Allocate memory for the integer array
    int *key = (int *)malloc(100 * sizeof(int));

    // Check if memory allocation was successful
    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    key[0] = 4;
    key[1] = 3;
    key[2] = 1;
    key[3] = 2;
    key[4] = 5;
    key[5] = 6;
    key[6] = 7;

    // // Convert command-line arguments to integers and store in the array
    // for (int i = 1; i < argc; i++) {
    //     key[i - 1] = atoi(argv[i]);
    // }


    char* s = encrypt("Attack postponed until two A.M.", 7, key);
    printf("%s\n", s);


    return 0;
}