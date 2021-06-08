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
    int solve(TreeNode* root,int &res)
    {
        if(root==NULL) return 0;
        int left=solve(root->left,res);
        int right=solve(root->right,res);
        // follow the straight path till now or straight from here
        int goStraight=max(max(left,right)+root->val,root->val);
        // bend and consider it root of tree
        int maxBendOrStraight = max(goStraight,left+right+root->val);
        res=max(maxBendOrStraight,res);
        return goStraight;
    }
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int res=INT_MIN;
        solve(root,res);
        return res;
    }
};