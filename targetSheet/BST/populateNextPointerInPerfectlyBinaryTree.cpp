#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void populate(Node*start) // connects its child with same level
    {
        Node*cur=start;
        while(start)
        {
            start->left->next=start->right;
            if(start->next)
            {
                start->right->next=start->next->left;
            }
            start=start->next;
        }
    }
    Node* connect(Node* root) {
         Node*leftNode=root;
       while(leftNode and leftNode->left) // move to ecery level before leaf level
       {
           populate(leftNode);
           leftNode=leftNode->left;
       }
        return root;
    }
};