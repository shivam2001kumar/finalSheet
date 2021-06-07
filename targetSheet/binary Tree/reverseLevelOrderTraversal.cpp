// printing last level to first level
#include<bits/stdc++.h>
using namespace  std;

  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    return 0;
}