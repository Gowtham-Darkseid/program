#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insert();
void delete_q();
void display();

// Global variables for queue management
int rear = -1, front = -1, queue[5], choice, n, i, t;

int main() {
    printf("Enter the queue size: ");
    scanf("%d", &n);
    
    do {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete_q();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Enter a correct choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert a customer into the queue
void insert() {
    if (rear == n - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Enter the ticket number for the customer: ");
        scanf("%d", &t);
        if (front == -1) {
            front = 0; // Initialize front if it's the first insertion
        }
        rear++;
        queue[rear] = t;
        printf("Customer with ticket number %d added to the queue.\n", t);
    }
}

// Function to delete a customer from the queue
void delete_q() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. No customers to serve.\n");
    } else {
        printf("Customer with ticket number %d is served and removed from the queue.\n", queue[front]);
        front++;
        // Reset the queue when all customers are served
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Current queue of customers: ");
        for (i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}
