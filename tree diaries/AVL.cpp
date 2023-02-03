
#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinarySearchTree{

public:
    struct Node {
        T key; // this is the data to be stored
        int height; // height of the subtree rooted at this node
        Node* left;
        Node* right; // these are the pointers to the left and right child respectively

        Node(T k)  // this will be used to create a new node every time we insert
        {
            key = k;
            height = 1;
            left = right = NULL;
        }
    };

    BinarySearchTree(){
        root = NULL;
    } ///this constructor will be invoked whenever you create an instance, and the root=NULL means the tree is empty

    void insert(T key)
    {
        root = insert(key, root);
    }

    void display()
    {
        display(root); ///first of all will diplay the root
        cout << endl;
    }

private:
    Node* root; //so that no one can alter the structure of the tree from outside the class

    Node* insert(T key, Node* current) ///current is the current node in which we want going to insert
    {
        if (current == NULL)
            return new Node(key);

        if (key < current->key)
            current->left = insert(key, current->left);
        else
            current->right = insert(key, current->right);

        current->height = max(height(current->left), height(current->right)) + 1;

        int balance = getBalance(current);

        // Left Left Case
        if (balance > 1 && key < current->left->key)
            return rightRotate(current);

        // Right Right Case
        if (balance < -1 && key > current->right->key)
            return leftRotate(current);

        // Left Right Case
        if (balance > 1 && key > current->left->key)
        {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }

        // Right Left Case
        if (balance < -1 && key < current->right->key)
        {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    void display(Node* leaf)
    { ///inorder traversal, left, root,right.
        if (leaf != NULL)
        {
            display(leaf->left);
            cout << leaf->key << " ";
            display(leaf->right);
        }
    }

    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalance(Node* node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
y->left = T2;

  // Update heights
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  // Return new root
  return x;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}


};

int main()
{
	
	BinarySearchTree <int> bst; // an instance of the class, it will invoke the constructor
	bst.insert(1);  //it will revoke the public insert function
	bst.insert(6);
	bst.insert(4);
	bst.insert(7);
	bst.insert(2);
	bst.insert(9);
	bst.insert(8);
	bst.insert(3);
	
	bst.display();
	
	return 0;
}
            