#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int new_data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = new_data;

    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(node **head, int new_data) {
    struct node *newNode = createNode(new_data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(node **head, int new_data) {
    struct node *newNode = createNode(new_data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void insertBeforeTail(node **head, int new_data) {
    struct node *newNode = createNode(new_data);

    struct node *tail = *head;
    while(tail->next->next != NULL) {
        tail = tail ->next;
    }

    newNode->next = tail->next;
    tail->next = newNode;
}

void printList(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    insertAtBeginning(&head, 15);
    insertAtEnd(&head, 18);
    insertAtBeginning(&head, 10);
    insertBeforeTail(&head, 25);
    insertAtEnd(&head, 28);
    insertAtBeginning(&head, 3);
    insertBeforeTail(&head, 25);
    
    printList(head);

    return 0;
}