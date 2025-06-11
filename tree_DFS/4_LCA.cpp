// Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Agar root hi p ya q ho to wahi return kar do.
// varna dfs se left aur right se p ya q ko dhundo. agar left me null ho to right return kar do kyuki right ke subtree me p ya q milega.
// similarly agar right null ho to left return kar do varna root return kar do kyuki dono p aur q left aur right me mile hain.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL || root==p || root==q)
                return root;
            TreeNode* left = lowestCommonAncestor(root->left , p , q);
            TreeNode* right = lowestCommonAncestor(root->right , p , q);
            if(left==NULL)
                return right;
            else if(right==NULL)
                return left;
            else
                return root;
        }
    };