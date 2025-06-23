// Problem Statement: https://www.codingninjas.com/codestudio/problems/ceil-in-bst_920546

// similarly as floor in BST, we can find ceil in BST , bas pehla condition change hoga
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    if(!node)
        return 0;
    int min = -1;
    while(node){
        if(node->data >= x){
            min = node->data;
            node = node->left;
        }
        else
            node = node->right;
    }
    return min;
}