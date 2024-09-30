#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
}

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    Node* tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// Function to insert at a specific position (1-based index)
void insertByPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    Node* temp = head;
    int count = 1;

    do {
        if (count == position - 1) {
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    cout << "Position out of bounds." << endl;
}

// Function to insert after a specific value
void insertByValue(int value, int afterValue) {
    Node* temp = head;

    do {
        if (temp->data == afterValue) {
            Node* newNode = new Node();
            newNode->data = value;
            Node* nextNode = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = nextNode;
            nextNode->prev = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << afterValue << " not found in the list." << endl;
}

// Function to display the doubly circular linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

// Function to delete the first node (head)
void deleteAtBeginning() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* tail = head->prev;
    Node* toDelete = head;

    if (head == tail) {
        head = nullptr;
    } else {
        tail->next = head->next;
        head->next->prev = tail;
        head = head->next;
    }

    delete toDelete;
}

// Function to delete the last node (tail)
void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* tail = head->prev;

    if (head == tail) {
        delete head;
        head = nullptr;
        return;
    }

    Node* newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    delete tail;
}

// Function to delete a node by value
void deleteByValue(int value) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    do {
        if (temp->data == value) {
            if (temp->next == temp) {
                head = nullptr;
            } else {
                Node* before = temp->prev;
                Node* after = temp->next;
                before->next = after;
                after->prev = before;

                if (temp == head) {
                    head = after;
                }
            }
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value " << value << " not found in the list." << endl;
}

// Function to delete a node at a specific position (1-based index)
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

    do {
        if (count == position) {
            Node* before = temp->prev;
            Node* after = temp->next;
            before->next = after;
            after->prev = before;
            delete temp;
            return;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    cout << "Position out of bounds." << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    display();  // Output: 5 <-> 10 <-> 20 <-> 30 <-> (head)

    insertByPosition(15, 3);
    display();  // Output: 5 <-> 10 <-> 15 <-> 20 <-> 30 <-> (head)

    insertByValue(25, 20);
    display();  // Output: 5 <-> 10 <-> 15 <-> 20 <-> 25 <-> 30 <-> (head)
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteByPosition(3);
    display();  // Output: 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> (head)

    deleteByValue(20);
    display();  // Output: 5 <-> 10 <-> 25 <-> 30 <-> (head)

    return 0;
}
