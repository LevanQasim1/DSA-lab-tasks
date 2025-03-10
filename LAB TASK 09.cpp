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

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList()
	{
		head = NULL;
	}

    void insertAtFirst(int val) 
	{
        Node* newNode = new Node(val);
        if (!head) 
		{
            head = newNode;
            head->next = head;
        } 
		else 
		{
            Node* temp = head;
            while (temp->next != head) 
			{
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int val) 
	{
        Node* newNode = new Node(val);
        if (!head) 
		{
            head = newNode;
            head->next = head;
        } 
		else 
		{
            Node* temp = head;
            while (temp->next != head) 
			{
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int val, int n) 
	{
        if (n < 0)
        {
        	return ;
		}
        if (n == 0) 
		{
            insertAtFirst(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        int count = 0;
        while (current->next != head && count < n - 1) 
		{
            current = current->next;
            count++;
        }
        if (current->next == head && count < n -1)
        {
        	return;
		}
        newNode->next = current->next;
        current->next = newNode;
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
        while (fast->next != head && fast->next->next != head) 
		{
            slow = slow->next;
            fast = fast->next->next;
        }
        insertAtNth(val, countNodes() / 2);
    }

    void displayForward() 
	{
        if (!head)
        {
        	 return;
		}
        Node* current = head;
        do 
		{
            cout << current->data << " ";
            current = current->next;
        } 
		while (current != head);
        cout << endl;
    }

    void displayReverse() 
	{
        if (!head) return;
        Node* current = head;
        Node* prev = nullptr;
        Node* temp = nullptr;
        do 
		{
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        } 
		while (current != head);
        head->next = prev;
        head = prev;
        displayForward(); 
        head = prev->next; 
        Node* temp2 = head;
        do
		{
            temp2 = temp2->next;
        }
		while(temp2->next != prev);
        temp2->next = head;

    }

    int countNodes() 
	{
        if (!head) return 0;
        Node* current = head;
        int count = 0;
        do 
		{
            count++;
            current = current->next;
        }
		while (current != head);
        return count;
    }
};

int main() {
    CircularLinkedList myList;
    myList.insertAtFirst(10);
    myList.insertAtLast(30);
    myList.insertAtNth(20, 1);
    myList.insertAtCenter(25);
    myList.displayForward();
    myList.displayReverse();
    return 0;
}
