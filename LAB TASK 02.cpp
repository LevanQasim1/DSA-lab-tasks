#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val)
	{
		data = val;
		next = NULL;
	}
};

class LinkedList {
public:
    Node* head;

    LinkedList()
	{
		head = NULL;
	}

    void insertAtStart(int val)
	{
        Node* newNode = new Node(val);
        if(head == NULL)
        {
        	head = newNode;
		}
		else
		{
		newNode->next = head;
        head = newNode;
		}
    }

    void insertAtEnd(int val)
	{
        Node* newNode = new Node(val);
        if (head != NULL) 
		{
            head = newNode;
        } 
		else 
		{
            Node* temp = head;
            while (temp->next) 
			{
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) 
		{
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtStart(10);
    myList.insertAtEnd(20);
    myList.insertAtStart(5);
    myList.insertAtEnd(30);
    return 0;
}
