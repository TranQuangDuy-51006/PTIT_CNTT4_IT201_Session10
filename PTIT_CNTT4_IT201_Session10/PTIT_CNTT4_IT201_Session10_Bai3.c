//
// Created by Admin on 04/07/2025.
//
//
// Created by Admin on 03/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    if(head == NULL) {
        return;
    }
    printf("%d ", head->data);
    printList(head->next);
}

Node* add(Node* head, int value) {
    Node* newNode = createNode(value);
    if(head == NULL) {
        return newNode;
    }
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int main() {
    Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    printList(head);
    printf("\n");
    int addNumber;
    scanf("%d", &addNumber);
    add(head, addNumber);
    printList(head);
    return 0;
}