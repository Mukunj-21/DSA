// Problem :https://leetcode.com/problems/average-of-levels-in-binary-tree/

// Root ko Queue me daalenge fir jab tak queue khali nahi hoti 
// tab tak loop chalayenge aur har baar queue se front element ko nikaalenge aur uske left aur right child ko queue me daalenge
// aur value ko vector me daalenge. tab tak jab tak queue khali nahi hoti.
// ans me vector ki jagah jo sum hoga usko count se divide karenge aur vector me daalenge.

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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> ans;
                if(root==NULL)
                    return ans;
                queue<TreeNode*> q;
                q.push(root);
                while(!q.empty()){
                    int s = q.size();
                    double sum = 0;
                    int count = 0;
                    for(int i=0;i<s;i++){
                        TreeNode* temp = q.front();
                        q.pop();
                        if(temp->left)
                            q.push(temp->left);
                        if(temp->right)
                            q.push(temp->right);
                        sum+=temp->val;
                        count++;
                    }
                    ans.push_back(sum/count);
                }
            return ans;
        }
    };