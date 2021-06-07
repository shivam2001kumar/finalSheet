#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int>ans;
	if(root==NULL)
	return ans;
	int flag=1;
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
	    vector<int>temp;
	    int sz=q.size();
	    while(sz--)
	    {
	        Node*t=q.front();
	        q.pop();
	        temp.push_back(t->data);
	        if(t->left) q.push(t->left);
	        if(t->right) q.push(t->right);
	    }
	    if(flag%2==0)
	        reverse(temp.begin(),temp.end());
	   for(int i=0;i<temp.size();i++) 
	    ans.push_back(temp[i]);
	    flag=!flag;
	}
	return ans;
}