#include <iostream>
using namespace std;
class BSTNode 
{
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) 
	{
		data = val;
		left = right = nullptr;
		
	}
};

class AVLNode 
{
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) 
	{
		data = val;
		height = '1';
		left = right = nullptr;
		
	}
};
class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, int val) 
	{
        if (!node) 
        {
        	return new BSTNode(val);
		}
        if (val < node->data)
        {  
		node->left = insert(node->left, val);
        }
        else
        {
        	    node->right = insert(node->right, val);
		}
        return node;
    }

    void inorder(BSTNode* node) 
	{
        if (!node) 
        {
        	return;
		}
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST()
	{
		head = nullptr;
	}

    void insert(int val) 
	{
        root = insert(root, val);
    }

    void displayInorder() 
	{
    	
        inorder(root);
        cout << endl;
    }
};
class AVL {
private:
    AVLNode* root;

    int height(AVLNode* node) 
	{
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) 
	{
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) 
	{
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) 
	{
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    AVLNode* insert(AVLNode* node, int val) 
	{
        if (!node)
        {
        	 return new AVLNode(val);
		}
        if (val < node->data)
    	{
    		node->left = insert(node->left, val);
		}
        else if (val > node->data)
        {
        	 node->right = insert(node->right, val);
		}
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        // Rotations
        if (balance > 1 && val < node->left->data)
            return rightRotate(node);
        if (balance < -1 && val > node->right->data)
            return leftRotate(node);
        if (balance > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(AVLNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    AVL() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

// --- Main Function ---
int main() {
    BST bst;
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(10);
    cout << "BST In-order: ";
    bst.displayInorder();

    AVL avl;
    avl.insert(30);
    avl.insert(20);
    avl.insert(40);
    avl.insert(10);
    cout << "AVL In-order: ";
    avl.displayInorder();

    return 0;
}

