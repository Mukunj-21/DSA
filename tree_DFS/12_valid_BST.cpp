//Problem : https://leetcode.com/problems/validate-binary-search-tree/description/

// recursion wise dekhna hai agar node ki value left se badi hai aur right se choti hai to false hogya 
// ye jo left aur right ka jo range hai usko maintain karna hai jab left me jaenge to node ki ko max me 
// rakhna h ki haan node ki value is se choti hi chahiye 
// aur right me jaenge to node ki value ko min me rakhna h ki haan node ki value is se badi hi chahiye

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
        bool valid(TreeNode* node , long min , long max){
            if(!node)
                return true;
            if(!((node->val>min)&&(node->val<max)))
                return false;
            return valid(node->left , min , node->val)&&valid(node->right , node->val , max);
        }
        bool isValidBST(TreeNode* root) {
            return valid(root , LONG_MIN , LONG_MAX);
        }
    };