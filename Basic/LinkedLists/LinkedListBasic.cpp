// This is a Singly Linked List (SLL), performing basic operations like:
// insertion
// deletion
// traversal, etc

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int data) {
        Node* temp = new Node(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insertAtTail(int data) {
        Node* temp = new Node(data);
        if (tail == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtPosition(int position, int data) {
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position == 1) {
            insertAtHead(data);
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
        if (nodeToInsert->next == nullptr) {
            tail = nodeToInsert;
        }
    }

    void deletion(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) tail = nullptr; 
            delete temp;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        int count = 1;
        while (current != nullptr && count < position) {
            prev = current;
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        prev->next = current->next;
        if (prev->next == nullptr) {
            tail = prev;
        }
        delete current;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtHead(5);
    list.print();
    list.insertAtTail(47);
    list.print();
    list.insertAtTail(98);
    list.print();
    list.insertAtHead(3);
    list.print();
    list.insertAtPosition(2, 21);
    list.print();
    list.deletion(2);
    list.print();
    return 0;
}
