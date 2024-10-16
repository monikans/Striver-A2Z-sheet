#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterValue(int value, int afterValue) {
    Node* temp = head;

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
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}
void insertAtPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    int count = 1;

    // Traverse to the position before where we want to insert
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

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
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    while (temp != nullptr && temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Value " << value << " not found." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}
void deleteAtPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    int count = 1;

    // Traverse to the node at the specified position
    while (temp != nullptr && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position " << position << " is out of bounds." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAfterValue(25, 20);
    insertAtPosition(27, 3);
    display();  // Output: 10 <-> 20 <-> 25 <-> 30 <-> NULL

    deleteAtBeginning();
    display();  // Output: 20 <-> 25 <-> 30 <-> NULL
    deleteAtEnd();
    display();  // Output: 20 <-> 25 <-> NULL
    deleteByValue(20);
    display();  // Output: 25 <-> NULL
    deleteAtPosition(2);
    display();
    return 0;
}
