#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;  // Global head pointer for the linked list

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node after a specific value
void insertAfterValue(int value, int afterValue) {
    Node* temp = head;

    // Traverse to find the node with the given value
    while (temp != nullptr && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << afterValue << " not found in the list." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a node at a specific position (1-based index)
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to find the position before the one to insert at
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete a node at the beginning
void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete a node at the end
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a node by value
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Function to delete a node at a specific position (1-based index)
void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to find the position before the one to delete
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

int main() {
    // Insertion examples
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfterValue(25, 20);
    insertAtPosition(15, 2);
    display();  // Output: 10 -> 15 -> 20 -> 25 -> 30 -> NULL

    // Deletion examples
    deleteAtBeginning();
    display();  // Output: 15 -> 20 -> 25 -> 30 -> NULL
    deleteAtEnd();
    display();  // Output: 15 -> 20 -> 25 -> NULL
    deleteByValue(20);
    display();  // Output: 15 -> 25 -> NULL
    deleteAtPosition(2);
    display();  // Output: 15 -> NULL

    return 0;
}
