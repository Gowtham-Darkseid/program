#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

int top = -1, stack[5], t, choice, n, i;

int main() {
    printf("Enter stack size (max 5):\n");
    scanf("%d", &n);

    if (n > 5 || n <= 0) {
        printf("Invalid stack size. Max size is 5.\n");
        return 1;
    }

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Enter a correct choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top == n - 1) {
        printf("Stack is full.\n");
    } else {
        printf("Enter stack value: ");
        scanf("%d", &t);
        top = top + 1;
        stack[top] = t;
        printf("%d pushed onto the stack.\n", t);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("%d popped from the stack.\n", stack[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack values:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
