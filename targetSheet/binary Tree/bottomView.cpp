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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>v;
        map<int,int> mp;
        queue<pair<Node*,int> >q;
        q.push({root,0});
        while(!q.empty())
        {
            Node*temp=q.front().first;
            int level=q.front().second;
            q.pop();
            mp[level]=temp->data;
            if(temp->left) q.push({temp->left,level-1});
            if(temp->right) q.push({temp->right,level+1});
        }
        for(auto x:mp)
        {
            v.push_back(x.second);
        }
        return v;
    }
};
