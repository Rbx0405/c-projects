#include <stdio.h>
#include <stdlib.h>

// Function to modify an array using pointers
void modifyArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) *= 2;  // Double each element using pointer arithmetic
    }
}

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int size;
    
    // Dynamic memory allocation for an array
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int)); // Allocating memory dynamically
    
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Taking input
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr + i)); // Using pointer notation
    }

    // Modify array using pointer arithmetic
    modifyArray(arr, size);

    // Display modified array
    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Demonstrating pointer swap function
    int x = 5, y = 10;
    printf("Before Swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After Swap: x = %d, y = %d\n", x, y);

    // Free allocated memory
    free(arr);

    return 0;
}