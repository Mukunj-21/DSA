//Problem : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// VERY IMPORTANT QUESTION
// initially to normally chalo ki tree ko traverse kar rhe hai aur har node ke liye x aur y coordinate store kar rhe hai (in map)
// but then we need to sort the nodes based on y coordinate and then x coordinate kyuki vertical order chaiye to column ko hi dekhenge
// so we will use map of map and multiset fir last me jab map ko traverse karenge to y coordinate se sort ho jayega aur x coordinate se bhi sort ho jayega



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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            if(!root)
                return {};
            map<int , map<int,multiset<int>>> m;
            queue<pair<TreeNode*,pair<int,int>>>q;
            q.push({root ,{0,0}});
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                int x = it.second.first;
                int y = it.second.second;
                m[y][x].insert(temp->val);
                if(temp->left)
                    q.push({temp->left,{x+1,y-1}});
                if(temp->right)
                    q.push({temp->right,{x+1,y+1}});
            }
            vector<vector<int>> ans;
            for(auto i:m){
                vector<int> v;
                for(auto j:i.second){
                    v.insert(v.end(),j.second.begin(),j.second.end());
                }
                ans.push_back(v);
            }
            return ans;
        }
    };