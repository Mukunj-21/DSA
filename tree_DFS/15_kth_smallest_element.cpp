// Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Inorder traversal ko yaad karo left me jao bilkul aur fir count ko check kro match kr rha h kya if yes then return the value
// else right me jaake continue the process

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
        int count = 0 , result = -1;
        void inorder(TreeNode* root , int k){
            if(!root)
                return;
            inorder(root->left , k);
            count++;
            if(count==k){
                result = root->val;
                return;
            }
            inorder(root->right , k);
        }
        int kthSmallest(TreeNode* root, int k) {
            inorder(root , k);
            return result;
        }
    };