#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str;
    int len;

    printf("Enter string length: ");
    scanf("%d", &len);

    // Allocate memory dynamically for the string
    str = (char*)malloc((len + 1) * sizeof(char)); // +1 for '\0'
    
    if (!str) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter string: ");
    scanf(" ");  // To consume newline from previous input
    fgets(str, len + 1, stdin);

    printf("You entered: %s", str);

    free(str); // Free memory
    return 0;
}