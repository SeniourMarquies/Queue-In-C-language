#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void Enqueue(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        front = rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }
}

void Dequeue() {
    if (front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }

    node* temp = front;
    front = front->next;
    free(temp);

}

void PrintQueue() {
    if (front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            Enqueue(value);
            break;

        case 2:
            Dequeue();
            PrintQueue();
            break;

        case 3:
            PrintQueue();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
        }
    }

    return 0;
}
