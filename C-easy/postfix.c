#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int items[MAX];
} Stack;

// Stack operations
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[s->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expr) {
    Stack s;
    s.top = -1;

    for (int i = 0; expr[i] != '\0'; i++) {
        // If the character is a digit, push it to the stack
        if (isdigit(expr[i])) {
            push(&s, expr[i] - '0'); // Convert char to int
        }
        // If the character is an operator, pop two values and perform the operation
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch (expr[i]) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&s, val1 / val2);
                    break;
                default:
                    printf("Invalid character encountered\n");
                    exit(1);
            }
        }
    }
    return pop(&s);
}

int main() {
    char expr[MAX];

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", expr);

    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);

    return 0;
}