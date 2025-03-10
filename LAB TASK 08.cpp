#include <iostream>
using namespace std;
class SNode {
public:
    int data;
    SNode* next;
    SNode(int val)
	{
		data = val;
		next = NULL;
	}
};

class SLinkedList {
public:
    SNode* head;
    SLinkedList()
	{
		head = NULL;
	}

    void insert(int val) 
	{
        SNode* newNode = new SNode(val);
        if (!head) 
		{
            head = newNode;
        }
		else 
		{
            SNode* current = head;
            while (current->next) 
			{
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() 
	{
        SNode* current = head;
        while (current) 
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val)
	{
		data = val;
		prev = next = NULL;
	}
};

class DLinkedList {
public:
    DNode* head;
    DNode* tail;
    DLinkedList()
	{
		head = tail = NULL;
	}

    void insert(int val) 
	{
        DNode* newNode = new DNode(val);
        if (!head) 
		{
            head = tail = newNode;
        }
		else 
		{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() 
	{
        DNode* current = head;
        while (current) 
		{
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


SLinkedList mergeSLists(SLinkedList list1, SLinkedList list2) 
{
    SLinkedList mergedList;
    SNode* current1 = list1.head;
    SNode* current2 = list2.head;

    while (current1) 
	{
        mergedList.insert(current1->data);
        current1 = current1->next;
    }
    while (current2) 
	{
        mergedList.insert(current2->data);
        current2 = current2->next;
    }
    return mergedList;
}
DLinkedList mergeDLists(DLinkedList list1, DLinkedList list2) 
{
    DLinkedList mergedList;
    DNode* current1 = list1.head;
    DNode* current2 = list2.head;

    while (current1) 
	{
        mergedList.insert(current1->data);
        current1 = current1->next;
    }
    while (current2) 
	{
        mergedList.insert(current2->data);
        current2 = current2->next;
    }
    return mergedList;
}

int main() {
   
    SLinkedList sList1, sList2;
    sList1.insert(1); sList1.insert(3);
    sList2.insert(2); sList2.insert(4);
    SLinkedList mergedSList = mergeSLists(sList1, sList2);
    cout << "Merged Singly Linked List: ";
    mergedSList.display();
    
    DLinkedList dList1, dList2;
    dList1.insert(5); dList1.insert(7);
    dList2.insert(6); dList2.insert(8);
    DLinkedList mergedDList = mergeDLists(dList1, dList2);
    cout << "Merged Doubly Linked List: ";
    mergedDList.display();

    return 0;
}
