#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define NOT_2_CLAS 1
#define error(code,message) do{fprintf(stderr, "%s\n", message);return code;}while(0)

char* decrypt(char* ciphertext, int m, int key[]) {

    // temporary key
    //int tempKey[] = {4,3,1,2,5,6,7};

    // Step 1: Count letters in ciphertext (including padding)
    int length = strlen(ciphertext); 

    // Step 2: divide cipherlength by m to obtain # of rows (n)
    int n = length/m;

    // Step 3: populate 2d array with ciphertext in correct position
    char matrix[n][m]; //instantiate matrix

    int cipherCount = 0;
    for (int i = 1; i <= m; i++) {
        //search key for index of current chunk
        for (int index = 0; index < m; index++){ //m is length of key array
            if (i == key[index]) { //found column index to concatenate PROBLEM IS HERE ACCESSING KEY
                //add column values to destination string
                for (int row = 0; row < n; row++) {
                   matrix[row][index] = ciphertext[cipherCount];
                   cipherCount++;
                }
            }
        }
    }

    char *decryptedText = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            strncat(decryptedText, &matrix[i][j], 1);
        }
    }

    printf("\nfunction is reaching here in decrypt\n");
    printf("%s", decryptedText);

    return decryptedText;





}