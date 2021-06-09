#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* solve(vector<int>&preorder,int s,int e)
    {
        if(s>e) return NULL;
        TreeNode*root=new TreeNode(preorder[s]);
        int i;
        for(i=s+1;i<=e;i++)
        {
            if(preorder[i]>root->val)
                break;
        }
        root->left=solve(preorder,s+1,i-1);
        root->right=solve(preorder,i,e);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int s=0,e=preorder.size()-1;
        return solve(preorder,s,e);
    }
};