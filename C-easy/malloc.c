#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int *arr = (int*)malloc(n * sizeof(int));
    
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input elements
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Display elements
    printf("Array elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Free memory
    free(arr);
    return 0;
}