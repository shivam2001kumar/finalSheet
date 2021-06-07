#include<bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
unordered_map<string,int>mp;
string solve(Node*root)
{
    if(root==NULL) return "@";
    if(root->left==NULL and root->right==NULL)
    {
        string temp;
        temp.push_back(root->data);
        return temp;
    }
    string s="";
    string l = solve(root->left);
    string r = solve(root->right);
    s.push_back(root->data);
    s+=l;
    s+=r;
    mp[s]++;
    return s;
}
bool dupSub(Node *root)
{
     //your code here
     mp.clear();
     solve(root);
     for(auto x:mp){
         if(x.second>=2) return true;
     }
     return false;
     
}