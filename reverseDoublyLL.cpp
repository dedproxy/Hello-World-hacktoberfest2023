#include <iostream>

// Define the structure for a doubly linked list node.
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Function to reverse a doubly linked list.
ListNode* reverseDoublyLinkedList(ListNode* head) {
    ListNode* current = head;
    ListNode* temp = nullptr;

    while (current != nullptr) {
        // Swap the prev and next pointers for the current node.
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node.
        current = current->prev;

        // If we've reached the end, update the head.
        if (current != nullptr && current->prev == nullptr) {
            head = current;
        }
    }

    return head;
}

// Function to print a doubly linked list forward.
void printDoublyLinkedListForward(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to print a doubly linked list backward.
void printDoublyLinkedListBackward(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr && current->next != nullptr) {
        current = current->next;
    }
    while (current != nullptr) {
        std::cout << current->val << " <-> ";
        current = current->prev;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->prev = head;
    head->next->next = new ListNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new ListNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    std::cout << "Original Doubly Linked List (Forward): ";
    printDoublyLinkedListForward(head);

    // Reverse the doubly linked list.
    head = reverseDoublyLinkedList(head);

    std::cout << "Reversed Doubly Linked List (Forward): ";
    printDoublyLinkedListForward(head);

    std::cout << "Reversed Doubly Linked List (Backward): ";
    printDoublyLinkedListBackward(head);

    // Clean up the memory (free the nodes).
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
