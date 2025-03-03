#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 3, cols = 4, i, j;
    
    // Allocate memory for rows
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++)
        matrix[i] = (int*)calloc(cols, sizeof(int)); // Allocating cols using calloc

    // Filling the matrix
    int count = 1;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            matrix[i][j] = count++;

    // Display the matrix
    printf("2D Array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
    
    return 0;
}