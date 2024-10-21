#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createNode(int new_data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = new_data;
        newNode->next = NULL;
        newNode->prev = NULL;

        return newNode;
}

void insertAtBeginning(struct node **head, int new_data) {
    struct node *newNode = createNode(new_data);

        if (*head == NULL) {
            *head = newNode;
        } else {
            newNode->next = *head;
            (*head)->prev = newNode;
        }
        *head = newNode;
}

void printList(struct node *head) {
    struct node *temp = head;

        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
}

int main(){
    struct node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    printList(head);
}