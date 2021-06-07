#include<bits/stdc++.h>
using namespace  std;

  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      queue<Node*>q;
      q.push(node);
      while(!q.empty())
      {
          Node*temp=q.front();
          q.pop();
          v.push_back(temp->data);
          if(temp->left) q.push(temp->left);
          if(temp->right) q.push(temp->right);
      }
      return v;
    }
};

int main()
{
    return 0;
}