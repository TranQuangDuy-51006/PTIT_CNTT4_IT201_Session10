//
// Created by Admin on 04/07/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

Node* printList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("data: %d \n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);
    printList(head);
    return 0;
}