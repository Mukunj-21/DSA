//Problem Link: https://leetcode.com/problems/clone-graph/

// isme normal dfs se graph ko clone karna hai pehle node ke liye insert karna hai map me aur temp create krke map me use bhi daal do 
// phir neighbors ke liye bhi dfs call karna hai aur unhe bhi map me daal do

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
        unordered_map<Node*,Node*> m;
        Node* dfs(Node* node){
            if(!node)
                return NULL;
            if(m.find(node) != m.end())
                return m[node];
            Node* temp = new Node(node->val);
            m[node] = temp;
            int n = node->neighbors.size();
            for(int i=0;i<n;i++){
                temp->neighbors.push_back(dfs(node->neighbors[i]));
            }
            return temp;
        }
        Node* cloneGraph(Node* node) {
            if(!node)
                return NULL;
            return dfs(node);
        }
    };