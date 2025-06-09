// Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/

// tree traverse karenge simply but queue me sirf node ki jagah uski depth bhi add karenge
// jab bhi leaf node milegi tab uski depth return kar denge
// nahi to left aur right child ko queue me daal denge aur depth ko increment kar denge

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
        int minDepth(TreeNode* root) {
            if(root==NULL)
                return 0;
            int count = 1;
            queue<pair<TreeNode* , int>> q;
            q.push({root,1});
            while(!q.empty()){
                auto [temp , depth] = q.front();
                q.pop();
                if(temp->left==NULL && temp->right==NULL)
                    return depth;
                if(temp->left)
                    q.push({temp->left , depth+1});
                if(temp->right)
                    q.push({temp->right , depth+1});
            }
            return 0;
        }
    };