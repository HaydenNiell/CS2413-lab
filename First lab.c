//Question 1: Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Code for creating a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;

}

// Code for reversing the list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    
    while (curr) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;       
    }
    
    return prev; 
}


// Code for printing the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Code to create a list from an array
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

// Main code to test and create a reversed list
int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* head1 = arrayToList(arr1, 5);
    
    printf("Original List: ");
    printList(head1);
    
    head1 = reverseList(head1);
    
    printf("Reversed List: ");
    printList(head1);

    return 0;
}
