// Problem : https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
        int maxDepth(TreeNode* root) {
            if (!root) {
                return 0;
            }
    
            queue<TreeNode*> q;
            q.push(root);
            int depth = 0;
    
            while (!q.empty()) {
                depth++;
                int levelSize = q.size();
    
                for (int i = 0; i < levelSize; i++) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
    
            return depth;        
        }
    };