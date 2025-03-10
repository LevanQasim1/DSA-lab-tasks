#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void insertAtPosition(int val, int position) {
        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(val);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Position exceeds list length." << endl;
            delete newNode; // Avoid memory leak
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtPosition(10, 0);
    myList.insertAtPosition(20, 1);
    myList.insertAtPosition(30, 1);
    myList.insertAtPosition(40, 3);
    myList.insertAtPosition(50, 5); //invalid position
    myList.display();
    return 0;
}
