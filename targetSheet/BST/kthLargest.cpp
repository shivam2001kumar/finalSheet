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


// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    public: int count=0; 
    int kthLargest(Node *root, int k)
    {
        //Your code here
        if(root==NULL) return -1;
        int right=kthLargest(root->right,k);
        if(right!=-1)
        {
            return right;
        }
        count++;
        if(count==k) return root->data;
        return kthLargest(root->left,k);
    }
    
};