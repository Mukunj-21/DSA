// Problem : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// ek stack bana lo jisme pehle right daal do taaki niche rahe vo aur fir upar left daal do
// aur jo upar ho use naye node ke right pe dalte jao aur left me null rkho 

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
        void flatten(TreeNode* root) {
            if(!root)
                return ;
            stack<TreeNode*> s;
            s.push(root);
            while(!s.empty()){
                TreeNode* temp = s.top();
                s.pop();
                if(temp->right)
                    s.push(temp->right);
                if(temp->left)
                    s.push(temp->left);
                if(!s.empty())
                    temp->right = s.top();
                temp->left = NULL;
            }
        }
    };