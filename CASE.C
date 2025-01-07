#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
// Queue structure
typedef struct {
 char queue[MAX][50];
 int front;
 int rear;
} Queue;
// Stack structure
typedef struct {
 int stack[MAX];
 int top;
} Stack;
// Initialize queue
void initQueue(Queue* q) {
 q->front = -1;
 q->rear = -1;
}
// Check if queue is empty
int isQueueEmpty(Queue* q) {
 return q->front == -1;
}
// Check if queue is full
int isQueueFull(Queue* q) {
 return q->rear == MAX - 1;
}
// Enqueue operation
void enqueue(Queue* q, char* name) {
 if (isQueueFull(q)) {
 printf("Queue is full! Cannot add more customers.\n");
 return;
 }
 if (isQueueEmpty(q)) {
 q->front = 0;
 }
 strcpy(q->queue[++q->rear], name);
 printf("Enqueue: %s added to the queue.\n", name);
}
// Dequeue operation
void dequeue(Queue* q, Stack* s) {
 if (isQueueEmpty(q)) {
 printf("Queue is empty! No customers to serve.\n");
 return;
 }
 char* customer = q->queue[q->front];
 printf("Dequeue: %s served. ", customer);
 // Simulate ticket generation and push to stack
 int ticketID = 100 + q->front;
 s->stack[++s->top] = ticketID;
 printf("Ticket ID: %d generated.\n", ticketID);
 if (q->front == q->rear) {
 q->front = q->rear = -1; // Reset queue when empty
 } else {
 q->front++;
 }
}
// Display queue
void viewQueue(Queue* q) {
 if (isQueueEmpty(q)) {
 printf("Queue is empty.\n");
 return;
 }
 printf("Queue: ");
 for (int i = q->front; i <= q->rear; i++) {
 printf("%s ", q->queue[i]);
 }
 printf("\n");
}
// Initialize stack
void initStack(Stack* s) {
 s->top = -1;
}
// Check if stack is empty
int isStackEmpty(Stack* s) {
 return s->top == -1;
}
// Undo last transaction
void undoTransaction(Stack* s) {
 if (isStackEmpty(s)) {
 printf("No transactions to undo.\n");
 return;
 }
 int ticketID = s->stack[s->top--];
 printf("Undo Last Transaction: Ticket ID %d removed.\n", ticketID);
}
// Main function
int main() {
 Queue q;
 Stack s;
 initQueue(&q);
 initStack(&s);
 int choice;
 char name[50];
 do {
 printf("\nTicket Counter System:\n");
 printf("1. Add customer to queue\n");
 printf("2. Serve customer (Dequeue)\n");
 printf("3. View queue\n");
 printf("4. Undo last transaction\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter customer name: ");
 scanf("%s", name);
 enqueue(&q, name);
 break;
 case 2:
 dequeue(&q, &s);
 break;
 case 3:
 viewQueue(&q);
 break;
 case 4:
 undoTransaction(&s);
 break;
 case 5:
 printf("Exiting system. Goodbye!\n");
 break;
 default:
 printf("Invalid choice. Please try again.\n");
 }
 } while (choice != 5);
 return 0;
}