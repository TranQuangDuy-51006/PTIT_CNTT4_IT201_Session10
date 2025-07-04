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

Node* deleteValue(Node* head, int value) {
    while(head != NULL && head->data == value) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    if(head == NULL) {
        return NULL;
    }

    Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(3);
    head->next->next->next->next->next = createNode(8);
    printList(head);
    printf("\n");
    int num;
    printf("Nhap so can xoa");
    scanf("%d", &num);
    head = deleteValue(head, num);
    printList(head);
    return 0;
}