// Problem :https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        Node* connect(Node* root) {
            if(!root) return NULL;
            queue<Node*> q;
            q.push(root);
            Node* ans;
            while(!q.empty()){
                int n = q.size();
                ans = NULL;
                while(n--){
                    Node * temp = q.front();
                    q.pop();
                    if(ans)
                        ans->next = temp;
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                    ans = temp;
                }
            }
                return root;
        }
    };