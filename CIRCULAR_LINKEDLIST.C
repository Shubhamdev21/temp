#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;
    return newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);

    printf("\n");
}

int searchElement(struct Node* head, int value) {
    if (head == NULL) {
        return 0;
    }

    struct Node* temp = head->next;

    do {
        if (temp->data == value) {
            return 1; // Found
        }
        temp = temp->next;
    } while (temp != head->next);

    return 0; // Not found
}

struct Node* deleteElement(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* current = head->next;
    struct Node* prev = head;

    do {
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            return head;
        }

        prev = current;
        current = current->next;
    } while (current != head->next);

    printf("Element not found in the list\n");
    return head;
}

int main() {
    struct Node* head = NULL;

    // Insert at the beginning
    head = insertAtBeginning(head, 8);
    head = insertAtBeginning(head, 55);
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 6);
    head = insertAtBeginning(head, 2);

    // // Print the circular linked list
    // printf("Circular Linked List: ");
    // printList(head);

    // Insert at the end
    head = insertAtEnd(head, 22);
    head = insertAtEnd(head, 5);

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList(head);

    // Search element
    int searchValue = 8;
    if (searchElement(head, searchValue)) {
        printf("The searched element %d is found in the list\n", searchValue);
    } else {
        printf("%d not found in the list\n", searchValue);
    }

    // Delete element
    int deleteValue = 55;
    head = deleteElement(head, deleteValue);

    // Print the circular linked list after deletion
    printf("Circular Linked List after deletion: ");
    printList(head);

    return 0;
}
