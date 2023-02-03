//// Part 4 BST
//// Not allowing duplicates


#include<bits/stdc++.h>
using namespace std;




template <typename T>
class BinarySearchTree{
	
	public:
		
		struct Node {

	T key; // this is the data to be stored
	Node* left;Node* right; // these are the pointers to the left and right child respectively
	
	Node(T k)  // this will be used to create a new node every time we insert
	{
		key=k;
		left=right=NULL;
		
		
	}
	
};
		
		BinarySearchTree(){
			root=NULL;
		}///this constructor will be invoked whenever you create an instance, and the root=NULL means the tree is empty
		
		void insert(T key)
		{
			
			if(root==NULL)
			root= new Node(key);///if the tree is empty then insert a new node
			
			else
			insert(key,root); /// if the tree is not empty, the key and root node will be passed.
			
		}
	
	void display() 
	{
		
      display(root);///first of all will diplay the root
      cout << endl;
    }
	
	private:
		Node* root; //so that no one can alter the structure of the tree from outside the class
		
		void insert(T key,Node* current) ///current is the current node in which we want going to insert
		{
			if(key<current->key)
			{
				if(current->left==NULL)
				current->left=new Node(key);//add a new key only if there is no left child
				
				else
				insert(key,current->left);///else go down for adding a new node
				
			}
			
			else if (key>current->key)
			{
				
					if(current->right==NULL)
				current->right=new Node(key);
				
				else
				insert(key,current->right);
			}
			
			else
			cout<<"No dupliactes here, "<<key<<" is a duplicate"<<endl;
			
		}
		
		void display(Node* leaf)
		 {///inorder traversal, left, root,right.
      if (leaf != NULL) 
	  {
        display(leaf->left);
        cout << leaf->key << " ";
        display(leaf->right);
                        }
         }
		
		
		
};

int main()
{
	
	BinarySearchTree <int> bst; // an instance of the class, it will invoke the constructor
	bst.insert(6);  //it will revoke the public insert function
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
