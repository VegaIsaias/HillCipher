//
//  Created by Isaias Perez Vega
//  ----------------------
//  Hill Cipher
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// CONSTANTS AND FUNCTION SIGNATURES
#define MAX_CHARS 10000
#define COLS_NUM_ECHO 80

int** readKey(char* filename, int** keyMatrix, int* matrixSize);
void printKey(int** keyMatrix, int* matrixSize);

int main(int argc, char** argv) {
    
    // MEM FOR KEY FILE NAME //
    char keyName[50]; strcpy(keyName, argv[1]);
    
    // OPEN KEY FILE AND READ //
    int matrixSize;
    int** keyMatrix = NULL;
    keyMatrix = readKey(keyName, keyMatrix, &matrixSize);
    
    printKey(keyMatrix, &matrixSize);
    
    // MEM FOR TEXT FILE
    char fileName[50]; strcpy(fileName, argv[2]);
    
    // MSG ARRAY VARS
    char characters[MAX_CHARS];
    int breaker = 0; int bigCounter = 0;
    int x = 0; char letter;
    
    // Open file containing message
    FILE* msgFile = fopen(fileName,  "r");
    
    printf("Plaintext: \n");
    
    // Save all alphabet characters with no spaces
    while((letter = fgetc(msgFile)) != EOF ) {
        if(isalpha(letter)){
                
            // Setting chars to lower-case and saving
            putchar(tolower(letter));
            characters[x] = tolower(letter);
            x++; breaker++;
                
            // # characters <= 80 per line
            if(breaker >= 80){
                printf("\n");
                breaker = 0;
            }
            // Keeps track of how big our plain text is
            bigCounter++;
        }
    }
    
    // Padding for plaintext
    int offset = bigCounter % COLS_NUM_ECHO;
    if (offset > 0) {
        int hold = bigCounter;
        for (int x = 0; x < COLS_NUM_ECHO - offset; x++) {
            characters[hold++] = putchar(120);
        }
    }
    
    // Done Using File
    fclose(msgFile);
    printf("\n\n");
    
    
    // ENCRYPT MSG //
    printf("Ciphertext:\n");
    int index = 0; int counter = 0; int temp3 = 0;
    // Run as long as we have characters
    while (index <= bigCounter) {
        int temp2 = 0;
        for (int x = 0; x < matrixSize; x++) {
            for (int y = 0 ; y < matrixSize; y++) {
                // Matrix multiplication
                temp2 += (keyMatrix[x][y] * characters[index + y]);
            }
            // Washing result
            temp3 = (temp2 % 26) + 'a';
            printf("%c", temp3);
            counter++;
            
            // Ouput formatting
            if(counter >= COLS_NUM_ECHO){
                printf("\n");
                counter = 0;
            }

        }
        // Junmping index by key size increments
        index += matrixSize;
    }
    printf("\n");
    return 0;
}

// OPEN KEY FILE, SAVE AND PRINT IT TO THE CONSOLE //
int** readKey(char* fileName, int** keyMatrix, int* matrixSize) {
    
    /// PASS FILE NAME TO FOPEN
    FILE* keyFile = fopen(fileName, "r");
    if (keyFile) {
        fscanf(keyFile, "%d", matrixSize);
        
        // Memory for matrix
        keyMatrix = malloc(sizeof(int*) * *matrixSize);
        for (int x = 0; x < *matrixSize; x++) {
            keyMatrix[x] = malloc(sizeof(int) * *matrixSize);
        }
        
        // Copying key to matrix
        for (int x = 0; x < *matrixSize; x++) {
            for (int y = 0; y < *matrixSize; y++) {
                fscanf(keyFile, "%d", &keyMatrix[x][y]);
            }
        }
        fclose(keyFile);
    } else {
        printf("File didnt load\n");
    }
    return keyMatrix;
}

// PRINT THE KEY FILE TO THE CONSOLE //
void printKey(int** keyMatrix, int* matrixSize){
    printf("Key Matrix: \n");
    for (int x = 0; x < *matrixSize; x++) {
        for (int y = 0; y < *matrixSize; y++) {
            printf("%d ", keyMatrix[x][y]);
        }
        printf("\n");
        
    }
    printf("\n");
}

