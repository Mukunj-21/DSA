//Problem: https://leetcode.com/problems/binary-tree-maximum-path-sum/

// simply dfs se leaf nodes tak jao aur vapis aate hue node ki val + left ya right side ka maximum lena hai 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int sum(TreeNode* node , int &ans){
            if(!node)
                return 0;
            int left = max(0,sum(node->left , ans));
            int right = max(0,sum(node->right,ans));
            ans = max(ans , node->val+left+right);
            return node->val + max(left,right);
        }
        int maxPathSum(TreeNode* root) {
            int ans = INT_MIN;
            sum(root , ans);
            return ans;
        }
    };