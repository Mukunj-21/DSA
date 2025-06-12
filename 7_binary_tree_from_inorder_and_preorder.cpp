//Problem: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// inorder ka loop recursion ki form me lgao aur jo inorder ki values hai unhe ek map me store krwlo ki haan is value ki ye position hai 
// ab we know ki preorder ka pehla element root hota hai to fir ab jo inorder me uski position hogi us se pehle jitne number h vo 
// root ke left me jaenge aur jo right me hai vo right me to isme ab hum recursion is basis pe lgaenge ki us root waale ki value dundh li 
// aur ab uske left me start se us root ka index -1 rahega aur right me index +1 se end tak aur fir end me root ko return krwa do bas 

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
    private:
        map<int,int>m;
        int ind = 0;
        TreeNode* helper(vector<int>&preorder , int start , int end ,map<int,int> &m ,int &ind){
            if(start>end)
                return NULL;
            int rootval = preorder[ind++];
            TreeNode* root = new TreeNode(rootval);
            int instart = m[rootval];
            root->left = helper(preorder, start, instart-1 , m , ind);
            root->right = helper(preorder, instart+1, end , m , ind);
            return root;
            
        }
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            map<int,int> m;
            for(int i=0;i<inorder.size();i++)
                m[inorder[i]] = i;
            int ind = 0;
            return helper(preorder , 0 , inorder.size()-1 , m , ind);
        }
    };