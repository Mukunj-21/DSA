//Problem : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// nodes ko index assign kardo aur fir width nikal lo


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
        int widthOfBinaryTree(TreeNode* root) {
            int ans = 0;
            if(!root)
                return ans;
            queue<pair<TreeNode*,long long>> q;
            q.push({root,0});
            while(!q.empty()){
                int n = q.size();
                int x = q.front().second;
                int first , last;
                for(int i=0;i<n;i++){
                    long long current = q.front().second-x;
                    TreeNode* temp = q.front().first;
                    q.pop();
                    if(i==0)
                        first = current;
                    if(i==n-1)
                        last = current;
                    if(temp->left)
                        q.push({temp->left , 2*current+1});
                    if(temp->right)
                        q.push({temp->right , 2*current+2});
                }
                ans = max(ans , last-first+1);
            }
            return ans;
        }
    };