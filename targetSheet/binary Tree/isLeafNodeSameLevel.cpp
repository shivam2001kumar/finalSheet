#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
  int ans=1;
  void solve(Node*root,int &ma,int h)
  {
      if(root==NULL) return;
      if(root->left==NULL and root->right==NULL)
      {
          if(ma==-1)
          {
              ma=h;
          }
          else
          {
              if(ma!=h)
              {
                  ans=0;
              }
          }
          return;
      }
      solve(root->left,ma,h+1);
      solve(root->right,ma,h+1);
  }
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        int ma=-1;
        int h=0;
        solve(root,ma,h);
        return ans;
        
    }
};