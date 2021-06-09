#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution
{
public:

    void populateNext(Node *root)
    {
        //code here
        static Node*prev=NULL;
        if(root==NULL) return;
        populateNext(root->left);
        if(prev!=NULL)
        {
            prev->next=root;
        }
        prev=root;
        populateNext(root->right);
    }
};