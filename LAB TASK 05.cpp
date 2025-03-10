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

    void insertAtEnd(int val) 
	{
        Node* newNode = new Node(val);
        if (head == NULL) 
		{
            head = newNode;
        } else 
		{
            Node* current = head;
            while (current->next) 
			{
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteFirstNode() 
	{
        if (head != NUll)
		{
			return ;
		}
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLastNode() 
	{
        if (head != NULL)
        {
        	return ;
		}
        if (head->next != NULL) 
		{
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while (current->next->next) 
		{
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    void deleteNthNode(int n) 
	{
        if (head !=NULL)
        {
        	return ;
		}
        if (n == 0) 
		{
            deleteFirstNode();
            return;
        }
        Node* current = head;
        int count = 0;
        while (current && count < n - 1) 
		{
            current = current->next;
            count++;
        }
        if (!current || !current->next) 
        {
        	return ;
		}
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void deleteCenterNode() 
	{
        if(head != NULL)
        {
        	return ;
		}
        if (!head->next) 
		{
            delete head;
            head = nullptr;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;
        while (fast && fast->next) 
		{
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev) 
		{
            prev->next = slow->next;
        } 
		else 
		{
            head = slow->next; //If the list has two nodes
        }
        delete slow;
    }

    void display() 
	{
        Node* current = head;
        while (current) 
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);
    myList.insertAtEnd(40);
    myList.insertAtEnd(50);

    cout << "Original list: ";
    myList.display();

    myList.deleteFirstNode();
    cout << "After deleting first node: ";
    myList.display();

    myList.deleteLastNode();
    cout << "After deleting last node: ";
    myList.display();

    myList.deleteNthNode(1);
    cout << "After deleting 2nd node: ";
    myList.display();

    myList.deleteCenterNode();
    cout << "After deleting center node: ";
    myList.display();

    return 0;
}
