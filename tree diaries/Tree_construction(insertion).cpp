//// Part 6 BST
//// Delete operation


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
	/////constructor	
		BinarySearchTree(){
			root=NULL;
		}///this constructor will be invoked whenever you create an instance, and the root=NULL means the tree is empty
		
    ///////insert function
		void insert(T key)
		{
			
			if(root==NULL)
			root= new Node(key);///if the tree is empty then insert a new node
			
			else
			insert(key,root); /// if the tree is not empty, the key and root node will be passed.
			
		}
    ///////display function	
	void display() 
	{
		
      display(root);///first of all will diplay the root
      cout << endl;
    }

///////search function	
	void search(T key)
	{
	    search(root,key);
	}
	
//////delete function
    void deleteNode(T key)
    {
        deleteNode(root,key);
    }
	
	private:
		Node* root; //so that no one can alter the structure of the tree from outside the class
		Node* next;
		Node* nextl;
		
		
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
         
         void search(Node* current,T key)
         {
             if(current!=NULL){
             if(key==current->key)
             cout<<"Found";
             
             else if (key<current->key)
             search(current->left,key);
             
             else 
             search(current->right,key);}
             
            else
             cout<<"Key "<<key<<" does not exist";
         }
         
         void deleteNode(Node* current, T key)
         {
             if(key==current->key)
             {
                 if(current->left==NULL  && current->right==NULL)
                  current=NULL;///this condition is for:
                 // either it is a leaf Node
                 // either it is the only Node
                 
                 else if(current->left==NULL)
                 {
                     ///if there is right child only
                     current->key=current->right->key;
                     current->right=NULL;
                 }
                 
                 else if(current->right=NULL)
                 {
                     //if there is only left child
                     current->key=current->left->key;
                     current->left=NULL;
                 }
                 
                 else
                 {
                      next=current->right;
                     if(next->left==NULL)
                     next->left=current->left;
                     
                     else
                      nextl=next->left;
                     nextl->left=current->left;
                     nextl->right=next;
                     next->left=NULL;
                 }
                 
             }
             
             else if (key<current->key)
             deleteNode(current->left,key);
             
             else
             deleteNode (current->right,key);
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
	cout<<endl;
	
	bst.deleteNode(3);
	bst.display();
	cout<<endl;
	
	bst.search(5000);
	
	return 0;
}
