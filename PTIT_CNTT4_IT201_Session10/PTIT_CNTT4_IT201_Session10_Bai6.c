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

int length(Node* head) {
    int count = 0;
    while(head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

void printList(Node* head) {
    if(head == NULL) {
        return;
    }
    printf("%d ", head->data);
    printList(head->next);
}

void printMid(Node* head) {
    int mid = length(head) / 2;
    if(head == NULL || head->next == NULL) {
        return;
    }
    Node* current = head;
    for(int i = 0; i <= mid; i++) {
        if(i == mid) {
            printf("Node %d: %d ", i +1, current->data);
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    
    printList(head);
    printf("\n");
    printMid(head);
    return 0;
}