#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    unordered_map<int,int>mp;
    int idx=0;
    Node* solve(int pre[],int in[],int l,int u)
    {
        if(l>u) return NULL;
        Node*res=new Node(pre[idx++]);
        if(l==u) return res;
        int mid = mp[res->data];
        res->left = solve(pre,in,l,mid-1);
        res->right = solve(pre,in,mid+1,u);
        return res;
        
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        mp.clear();
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        Node*res=solve(pre,in,0,n-1);
        return res;
        
    }
};