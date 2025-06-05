// Problem : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Root ko Queue me daalenge fir jab tak queue khali nahi hoti 
// tab tak loop chalayenge aur har baar queue se front element ko nikaalenge aur uske left aur right child ko queue me daalenge
//  aur value ko vector me daalenge. tab tak jab tak queue khali nahi hoti. fir vector ko ans me daalenge aur return karenge.
// bas last me ans ko reverse kar denge.

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
        vector<vector<int>> reverselevelOrder(TreeNode* root) {
            vector<vector<int>> ans;
            if(root==NULL)
                return ans;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int s = q.size();
                vector<int> v;
                for(int i=0;i<s;i++){
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                    v.push_back(temp->val);
                }
                ans.push_back(v);
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };