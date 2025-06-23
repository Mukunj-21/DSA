// Problem: https://www.codingninjas.com/codestudio/problems/floor-in-bst_920546?leftPanelTab=0

// agar value X se choti ya barabar hai to us value ko max me store kar do aur right subtree me jao.
// agar null aajaye ya fir value X se badi value mile to left subtree me jao.


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int max = -1;
    if(!root)
        return 0;
    while(root){
        if(root->val <= X){
            max = root->val;
            root = root->right;    
        }
        else
            root = root->left;
    }
    return max;
}