//Problem : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

// approach is ek nayi class banao jo contain karega har node ki minimum value, maximum value, sum of the subtree and a boolean
// to check if it is a BST or not. ab normal post order traversal lagaenge ki left me gye fir right me gye aur agar left aur right
// dono BST hai aur vo particular node bhi hai to currSum me uski value aur left aur right ke sum ko add karenge. aur return krdenge 
// minimum aur maximum value ko. aur agar vo BST nahi hai to return krdenge INT_MIN aur INT_MAX aur sum 0 aur isBst false.

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

 class NodeValue{
    public:
        int mini , maxi , sum;
        bool isBst;
        NodeValue(int mini , int maxi , int sum , bool isBst){
            this->mini = mini;
            this->maxi = maxi;
            this->sum = sum;
            this->isBst = isBst;
        }
};
class Solution {
public:
    int ans = 0;
    NodeValue helper(TreeNode* node){
        if(!node)
            return NodeValue(INT_MAX , INT_MIN , 0 , true);
        auto left = helper(node->left);
        auto right = helper(node->right);
        if(left.isBst && right.isBst && node->val > left.maxi && node->val < right.mini){
            int currSum = node->val + left.sum + right.sum;
            ans = max(ans , currSum);
            return NodeValue(min(node->val , left.mini) , max(node->val , right.maxi) , 
                            currSum , true);
        }
        return NodeValue(INT_MIN , INT_MAX , 0 , false);
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};