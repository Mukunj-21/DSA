//Problem: https://leetcode.com/problems/symmetric-tree/

// recursion se root ke left aur right me jao aur fir agar unki value different hai to return false else dive deeper to the
// left of root1 and right of root2 and vice versa

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
        bool check(TreeNode* root1 , TreeNode* root2){
            if(!root1||!root2)
                return root1==root2;
            if(root1->val!=root2->val)
                return false;
            return check(root1->left,root2->right)&&check(root2->left,root1->right);
        }
        bool isSymmetric(TreeNode* root) {
            if(!root)
                return true;
            return check(root->left , root->right);
        }
    };