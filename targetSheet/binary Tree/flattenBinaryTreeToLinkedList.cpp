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
    void flatten(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) return;
        if(root->left)
        {
            flatten(root->left);
            TreeNode*temp=root->right;
            root->right=root->left;
            root->left=NULL;
            TreeNode*curr=root->right;
            while(curr->right)
            {
                curr=curr->right;
            }
            curr->right=temp;
            
            
        }
        flatten(root->right);
    }
};