#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void push();
void pop();
void display();

// Global variables for stack management
int stack[5], top = -1, maxSize, choice, ticketID;

int main() {
    printf("Enter the maximum size of the ticket history stack: ");
    scanf("%d", &maxSize);

    do {
        printf("\n1. Add Ticket (Push)\n2. Reverse Last Ticket (Pop)\n3. View Ticket History\n4. Exit\n");
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
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a ticket to the stack
void push() {
    if (top == maxSize - 1) {
        printf("Ticket history stack is full. Cannot add more tickets.\n");
    } else {
        printf("Enter the ticket ID to add: ");
        scanf("%d", &ticketID);
        top++;
        stack[top] = ticketID;
        printf("Ticket ID %d added to history.\n", ticketID);
    }
}

// Function to reverse the most recent ticket transaction (pop operation)
void pop() {
    if (top == -1) {
        printf("Ticket history stack is empty. No tickets to reverse.\n");
    } else {
        printf("Reversing the transaction for ticket ID %d.\n", stack[top]);
        top--;
    }
}

// Function to display the current ticket history stack
void display() {
    if (top == -1) {
        printf("Ticket history stack is empty.\n");
    } else {
        printf("Current ticket history:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
