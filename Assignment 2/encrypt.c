#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define NOT_2_CLAS 1
#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)


// plaintext = text to be encrypted
// key = permutation of #'s 1 -> m
// m = length of key and # of columns
char* encrypt(char* plaintext, int m, int key[]) { //

    //char ciphertext[100]; //initialize final string
    char *ciphertext = (char *)malloc(100 * sizeof(char));
    int length; //initialize string length variable
    int n;

    length = strlen(plaintext); 
    char cleanStr[length]; //where parsed plaintext will be stored

    // Step 1: store letters in new string and convert to lower case
    int temp = 0; //counter for cleanString
    for (int i = 0; i < length; i++) {
        
        if (isalpha(plaintext[i]) != 0) {
            char c = tolower(plaintext[i]);
            cleanStr[temp] = c;
            temp++;
        }
    }
    
    //Step 2: get value of n and round up
    length = strlen(cleanStr); //actual value of l
    n = ceil((length * 1.0) / m);

    // Step 3: create and populate matrix
    char matrix[n][m]; 

    temp = 0;
    int numCharToFill = (n * m) - length; //gives empty spaces after plaintext in 2D array
    char beginningChar = 122 - numCharToFill; //gives first char 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp < length-1) {
                matrix[i][j] = cleanStr[temp];
                temp++;
            }
            else {
                if (beginningChar <= 123) { //populate until z character
                    matrix[i][j] = beginningChar;
                    beginningChar++;
                }
                else {
                    continue; //would only hit this on the very last iteration of nested for loop
                }
                 
            }
        }
    }

    // //test output of encryption 2d array
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%c", matrix[i][j]);   
    //     }
    // }

    // Step 4: Concatenate letters from 2d array in order of key

        // Sample key permutation: [4,3,1,2,5,6,7]
    
    // for loop run from 1 -> m 
    // find the index position of 1 and print all column values (chunk 1 -> column 2)
    // empty destination string "ciphertext", add all column values, then continue iteration 

    //int tempKey[] = {4,3,1,2,5,6,7};


    for (int i = 1; i <= m; i++) {
        //search key for index of current chunk
        for (int index = 0; index < m; index++){ //m is length of key array
            if (i == key[index]) { //found column index to concatenate PROBLEM IS HERE ACCESSING KEY
                //add column values to destination string
                for (int row = 0; row < n; row++) {
                    //ciphertext[strlen(ciphertext)] = matrix[row][index]; didnt work
                    //strcat(ciphertext, matrix[row][index]); didnt work
                    strncat(ciphertext, &matrix[row][index], 1);
                }
            }
        }
    }
    
    // printf("\nfunction is reaching here in encrypt\n");
    // printf("%s", ciphertext);
    
    return ciphertext;
}