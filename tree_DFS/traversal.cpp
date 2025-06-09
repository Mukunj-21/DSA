// Problem: Given a binary tree, return its inorder, preorder, and postorder traversal as vectors.

// simply recursion use karni hai aur ek tree ke extreme point tak jao then backpropagate 
// and collect the data in the order required.

vector<int> traversal(Node* root){
    vector<int> result;
    inorder(root, result);
    return result;
}
void inorder(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}
void preorder(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->data);
    preorder(root->left, result);
    preorder(root->right, result);
}
void postorder(Node* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->data);
}