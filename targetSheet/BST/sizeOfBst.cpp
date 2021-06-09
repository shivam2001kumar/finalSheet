#include<bits/stdc++.h>
using namespace std;

struct Node
 {
     int data;
     Node* left;
     Node* right;
}; 

/* Computes the number of nodes in a tree. */
int getSize(Node* node)
{
   // Your code here
   if(node==NULL) return 0;
   int sizeLeft=0,sizeRight=0;
   if(node->left)
   {
       sizeLeft=getSize(node->left);
   }
   if(node->right)
   {
       sizeRight=getSize(node->right);
   }
   int temp=sizeLeft+sizeRight+1;
   return temp;
}