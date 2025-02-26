//Question 2: Remove a value from the linked list.

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Code to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Code to remove the node with the same value as a given number
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    struct ListNode* prev = NULL;
    struct ListNode* current = head;

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
            free(current);
            current = prev->next; 
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}

// Code to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);  
        head = head->next;     
    }
    printf("NULL\n");
}

// Code to convert an array to a list
struct ListNode* arrayToList(int arr[], int size) {
    if (size == 0) return NULL;

    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Main code to test if it removes the selected number
int main() {
    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    
    struct ListNode* head = arrayToList(arr, 7);

    printf("Original List: ");
    printList(head);

    head = removeElements(head, val);

    printf("List after removing %d: ", val);
    printList(head);

    return 0;
}
