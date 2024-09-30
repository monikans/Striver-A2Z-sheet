#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Function to insert at a specific position (1-based index)
void insertByPosition(int value, int position) {
    Node* newNode = new Node();
    newNode->data = value;

    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count < position - 1) {
        cout << "Position out of bounds." << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert after a specific value
void insertByValue(int value, int afterValue) {
    Node* temp = head;

    do {
        if (temp->data == afterValue) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << afterValue << " not found in the list." << endl;
}

// Function to display the circular list
void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

// Function to delete at the beginning
void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    Node* toDelete = head;
    if (head->next == head) {
        head = nullptr;
    } else {
        temp->next = head->next;
        head = head->next;
    }
    delete toDelete;
}

// Function to delete at the end
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    while (temp->next->next != head) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
}

// Function to delete at a specific position (1-based index)
void deleteByPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head || count < position - 1) {
        cout << "Position out of bounds." << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// Function to delete a specific value
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == value) {
        deleteAtBeginning();
        return;
    }

    Node* temp = head;
    do {
        if (temp->next->data == value) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << value << " not found." << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    display();  // Output: 5 -> 10 -> 20 -> 30 -> (head)

    insertByPosition(15, 3);
    display();  // Output: 5 -> 10 -> 15 -> 20 -> 30 -> (head)

    insertByValue(25, 20);
    display();  // Output: 5 -> 10 -> 15 -> 20 -> 25 -> 30 -> (head)

    deleteByPosition(3);
    display();  // Output: 5 -> 10 -> 20 -> 25 -> 30 -> (head)

    deleteByValue(20);
    display();  // Output: 5 -> 10 -> 25 -> 30 -> (head)

    return 0;
}
