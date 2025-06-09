// Problem : https://www.geeksforgeeks.org/level-order-successor-of-a-node-in-binary-tree/

Node* levelOrderSuccessor(Node* root, Node* key){
    if (root == NULL)
        return NULL;
    if (root == key) {
        if (root->left)
            return root->left;
        else if (root->right)
            return root->right;
        else
            return NULL;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(nd->left);
        if (temp->right != NULL)
            q.push(nd->right);
        if (temp == key)
            break;
    }
    return q.front();
}