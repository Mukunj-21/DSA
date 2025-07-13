//Problem : https://leetcode.com/problems/copy-list-with-random-pointer/

// is way me kro ki pehli traversal me hash map ke andar new nodes banalo har 1 node ke corresponding
// fir second traversal me unhe link bhi kar do 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(!head)
                return NULL;
            unordered_map<Node* , Node*> m;
            Node* curr = head;
            while(curr){
                m[curr] = new Node(curr->val);
                curr = curr->next;
            }
            curr = head;
            while(curr){
                m[curr]->next = m[curr->next];
                m[curr]->random = m[curr->random];
                curr = curr->next;
            }
            return m[head];
        }
    };