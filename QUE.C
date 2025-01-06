#include <stdio.h>
#include <stdlib.h>

void insert();
void removeElement();
void display();

int rear = -1, front = -1, queue[5], t, choice, n, i;

int main() {
    printf("Enter the queue size (max 5):\n");
    scanf("%d", &n);

    if (n > 5 || n <= 0) {
	printf("Invalid queue size. Max size is 5.\n");
	return 1;
    }

    do {
	printf("\n1. Insert\n2. Remove\n3. Display\n4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		insert();
		break;
	    case 2:
		removeElement();
		break;
	    case 3:
		display();
		break;
	    case 4:
		printf("Exiting program.\n");
		exit(0);
	    default:
		printf("Enter the correct choice.\n");
	}
    } while (choice != 4);

    return 0;
}

void insert() {
    if (rear == n - 1) {
	printf("Queue is full.\n");
    } else {
	printf("Enter the queue value: ");
	scanf("%d", &t);
	if (front == -1) {
	    front = 0; // Initialize front if it's the first element
	}
	rear = rear + 1;
	queue[rear] = t;
	printf("%d inserted into the queue.\n", t);
    }
}

void removeElement() {
    if (front == -1 || front > rear) {
	printf("Queue is empty.\n");
    } else {
	printf("%d removed from the queue.\n", queue[front]);
	front = front + 1;
    }
}

void display() {
    if (front == -1 || front > rear) {
	printf("Queue is empty.\n");
    } else {
	printf("Queue values:\n");
	for (i = front; i <= rear; i++) {
	    printf("%d\t", queue[i]);
	}
	printf("\n");
    }
}
