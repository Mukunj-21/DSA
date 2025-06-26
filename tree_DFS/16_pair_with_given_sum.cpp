// Problem :https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// 1 set banalo aur while traversing the tree agar k-root->val present hai to return true else traverse krte jao ni mila to false

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
        bool solve(TreeNode* root , unordered_set<int>&set , int k ){
            if(!root)
                return false;
            if(set.count(k-root->val))
                return true;
            set.insert(root->val);
            return solve(root->left , set , k) || solve(root->right , set , k);
        }
        bool findTarget(TreeNode* root, int k) {
            unordered_set<int> set;
            return solve(root , set , k);
        }
    };