#include<bits/stdc++.h>
using namespace std;

class minMax
{
    public:
    int mn,mx;
    bool isBST;
    int size;
    minMax()
    {
        mn=INT_MAX;
        mx=INT_MIN;
        size=0; 
        isBST=true;
    }
};

struct node
{
    int data;
    node*left,*right;

};

minMax* largest(node*root)
{
    if(root==NULL) //leaf node
    {
        return new minMax();
    }

    // post order traversal
    minMax*left=largest(root->left);
    minMax*right=largest(root->right);
    minMax*m=new minMax();

    // condition for no BST
    if(left->isBST==false or right->isBST==false or root->data < left->mx or root->data >= right->mn)
    {
        m->isBST=false;
        m->size=max(left->size,right->size);
        return m;
    }
    // now it is bst
    m->isBST=true;
    m->size=left->size+right->size+1;
    m->mn=root->left?left->mn:root->data;
    m->mx=root->right?right->mx:root->data;
    return m;

}