#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a tree created from postorder and inoreder traversals.
 unordered_map<int,int>mp;
    int idx;
    Node* solve(int post[],int in[],int l,int u)
    {
        if(l>u) return NULL;
        Node*res=new Node(post[idx--]);
        if(l==u) return res;
        int mid = mp[res->data];
        res->right = solve(post,in,mid+1,u);
        res->left = solve(post,in,l,mid-1);
        return res;
        
        
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    idx=n-1;
    mp.clear();
        for(int i=0;i<n;i++)
        {
            mp[in[i]]=i;
        }
        Node*res=solve(post,in,0,n-1);
        return res;
}