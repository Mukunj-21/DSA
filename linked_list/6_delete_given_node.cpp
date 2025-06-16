// Problem: https://leetcode.com/problems/delete-node-in-a-linked-list/

// given node ko delete karna hai to delete to aise kr ni skte bina prev pta chale 
// to fir humne us node ki value ko next node ki value se replace kr dena hai

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        void deleteNode(ListNode* node) {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    };