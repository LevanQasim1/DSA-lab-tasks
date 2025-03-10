#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val)
	{
		data= val;
		prev = NULL;
		next = NULL;
	}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList()
	{
		head = tail = NULL;
	}

    void insertAtFirst(int val) 
	{
        Node* newNode = new Node(val);
        if (head != NULL) 
		{
            head = tail = newNode;
        } 
		else 
		{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int val) 
	{
        Node* newNode = new Node(val);
        if (!tail) 
		{
            head = tail = newNode;
        }
		else 
		{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtNth(int val, int n) 
	{
        if (n < 0) return;
        if (n == 0) 
		{
            insertAtFirst(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        int count = 0;
        while (current && count < n - 1) 
		{
            current = current->next;
            count++;
        }
        if (!current)
        {
        	return ;
		}
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) 
        {
        	current->next->prev = newNode;
        	current->next = newNode;
        	
		}
        
        if (!newNode->next) 
        {
        	tail = newNode;
		}
    }

    void insertAtCenter(int val) 
	{
        if (!head) 
		{
            insertAtFirst(val);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) 
		{
            slow = slow->next;
            fast = fast->next->next;
        }
        insertAtNth(val, countNodes()/2);
    }

    void displayForward() 
	{
        Node* current = head;
        while (current) 
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() 
	{
        Node* current = tail;
        while (current) 
		{
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    int countNodes()
	{
        int count = 0;
        Node* current = head;
        while(current)
		{
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList myList;
    myList.insertAtFirst(10);
    myList.insertAtLast(30);
    myList.insertAtNth(20, 1);
    myList.insertAtCenter(25);
    myList.displayForward(2);
    myList.displayBackward(3);
    return 0;
}
