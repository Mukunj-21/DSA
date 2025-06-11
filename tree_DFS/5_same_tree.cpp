//Problem: https://leetcode.com/problems/same-tree/

// simply left aur right me traverse karte rho agar dono null pe aajaye to true return hojaega 
// agar ab baad me dono mese koi bhi null hua to false aajaega ya fir agar value hi alag hai to false aajaega

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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p && !q)
                return true;
            if( !p || !q || p->val!=q->val)
                return false;
            return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
        }
    };