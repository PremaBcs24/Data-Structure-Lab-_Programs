#include <stdio.h>
#define MAX 5  // You can change the size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert element into the queue
void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) { // First element insertion
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}

// Function to delete element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    int deletedValue = queue[front];
    front++;
    printf("%d deleted from the queue.\n", deletedValue);
    if (front > rear) { // Reset queue if it becomes empty
        front = rear = -1;
    }
}

// Function to display elements of the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\nQueue Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
