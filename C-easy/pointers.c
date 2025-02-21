#include <stdio.h>

int main() {
    int num = 10;
    int *ptr = &num;  // Pointer to num

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Pointer ptr holds address: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);

    *ptr = 20;  // Modifying value using pointer
    printf("Updated value of num: %d\n", num);

    return 0;
}