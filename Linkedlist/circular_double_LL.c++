#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

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

    tail->prev->next = head;
    head->prev = tail->prev;
    delete tail;
}

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

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtBeginning(5);
    display();  // Output: 5 <-> 10 <-> 20 <-> 30 <-> (head)

    deleteAtBeginning();
    display();  // Output: 10 <-> 20 <-> 30 <-> (head)
    deleteAtEnd();
    display();  // Output: 10 <-> 20 <-> (head)
    deleteByValue(20);
    display();  // Output: 10 <-> (head)

    return 0;
}
