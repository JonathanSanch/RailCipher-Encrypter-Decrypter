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


int main(int argc, char* argv[]){

    //CLA checks
		
	if(!check_integer(argv[1])) 
    {
        error(2, "railcipher: Fatal Error! first command-line argument must be a valid integer");
    }
		
	if(!check_integer(argv[2]))
    {
        error(3, "railcipher: Fatal Error! second command-line argument must be a valid integer");
    }

    // temporary hardcoded key array
    //int key = {4,3,1,2,5,6,7};

    // Allocate memory for the integer array
    int *key = (int *)malloc(100 * sizeof(int));

    // Check if memory allocation was successful
    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // key[0] = 4;
    // key[1] = 3;
    // key[2] = 1;
    // key[3] = 2;
    // key[4] = 5;
    // key[5] = 6;
    // key[6] = 7;

    int m = atoi(argv[1]); //store m 

    // Convert command-line arguments to integers and store in the array
    for (int i = 2; i < argc; i++) {
        key[i - 2] = atoi(argv[i]);
    }

    

    char* s = encrypt("Attack postponed until two A.M.", m, key);
    
    printf("\n");
    char* d = decrypt("TTNAAPTMTSUOAODWCOIXKNLYPETZ", m, key);

    printf("\nThe following is testing the returns of the functions:\n"); 
    printf("%s\n", s);
    printf("%s\n", d);


    return 0;
}