// There are two ways to Reverse a Singly Linked List
// 1. Iterative
// 2. Recursive


#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Iterative reversal
    void reverseListIterative() {
        if (head == NULL || head->next == NULL)
            return;
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* temp = NULL;
        tail = head;
        while (current != NULL) {
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        head = previous;
    }

    // Recursive reversal
    ListNode* reverseListRecursiveHelper(ListNode* node) {
        if (node == NULL || node->next == NULL)
            return node;
        ListNode* newHead = reverseListRecursiveHelper(node->next);
        node->next->next = node;
        node->next = NULL;
        return newHead;
    }

    void reverseListRecursive() {
        tail = head;
        head = reverseListRecursiveHelper(head);
    }

    void append(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        ListNode* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);

    cout << "Original List: ";
    myList.printList();

    myList.reverseListIterative();
    cout << "Reversed List (Iterative): ";
    myList.printList();

    myList.reverseListRecursive();
    cout << "Reversed List (Recursive): ";
    myList.printList();

    return 0;
}
