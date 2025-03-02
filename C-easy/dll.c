#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node dynamically
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next) temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node by value
void deleteNode(struct Node** head, int val) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // If head node is to be deleted
    if (temp->data == val) {
        *head = temp->next;
        if (*head) (*head)->prev = NULL;
        free(temp);
        return;
    }

    while (temp && temp->data != val)
        temp = temp->next;

    if (!temp) return; // Value not found

    temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
}

// Display the list forward
void displayForward(struct Node* head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Display the list backward
void displayBackward(struct Node* tail) {
    while (tail) {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

// Free the entire list
void freeList(struct Node** head) {
    struct Node* temp = *head;
    while (temp) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

// Main function
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    printf("Doubly Linked List (Forward): ");
    displayForward(head);

    // Move to last node for backward display
    struct Node* tail = head;
    while (tail->next) tail = tail->next;

    printf("Doubly Linked List (Backward): ");
    displayBackward(tail);

    deleteNode(&head, 20);
    printf("After Deletion (Forward): ");
    displayForward(head);

    freeList(&head);
    return 0;
}