#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
    Node* findMin(Node*root)
    {
        if(root==NULL) return NULL;
        Node*curr=root;
        while(curr->left)
        {
            curr=curr->left;
        }
        return curr;
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        if(x==NULL or root==NULL) return NULL;
        // if x has right subtree
        Node*successor=NULL;
        if(x->right)
        {
            return findMin(x->right);
        }
        else // no right subtree then find find ancestor of which x is in left subtree of it
        {
            
            Node *ancesstor=root;
            while(ancesstor!=x)
            {
                if(x->data < ancesstor->data)
                {
                    successor=ancesstor;
                    ancesstor=ancesstor->left;
                }
                else
                    ancesstor=ancesstor->right;
                
            }
        }
        return successor;
    }
};