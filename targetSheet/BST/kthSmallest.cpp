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
  int count=0;
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int k)
    {
        //add code here.
        if(root==NULL) return -1;
        int left=KthSmallestElement(root->left,k);
        if(left!=-1)
        {
            return left;
        }
        count++;
        if(count==k) return root->data;
        return KthSmallestElement(root->right,k);
    }
};