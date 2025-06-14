//Problem: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// sorted array hai aur BST banana hai to fir jo middle element hoga vahi root hoga aur jo us se left side hai vo left tree me jaega 
// aur right waali side array ki root ke right me fir left aur right side ke liye same process chalega

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
        TreeNode* helper(vector<int> &nums , int start , int end){
            if(start>=end)
                return NULL;
            int mid=(start+end)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = helper(nums , start , mid);
            root->right = helper(nums , mid+1 , end);
            return root;
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return helper(nums , 0 , nums.size());
        }
    };