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

    if(head == NULL) {
        *head = newNode;
    }
    else {
        newNode->next = *head;
        *head = newNode;
    }

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
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 1);
    printList(head);

    return 0;
}