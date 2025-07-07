//Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// temp initialize krlo dummy se aur ek num jo ki min value pe h abhi agar head ki val num se alag h to duplicate check kro 
// head aur uske next ke liye agar hai to num ko update krdo aur temp ke next ko NULL krdo kyunki duplicate h if not duplicate
// then temp ke next ko head krdo aur temp ko ab head se start krdo . finally return dummy->next

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* dummy = new ListNode(0,head);
            ListNode* temp = dummy;
            int num = -101;
            while(head){
                if(head->val != num){
                    if(head->next && head->next->val == head->val){
                        num = head->val;
                        temp->next = NULL;
                    }
                    else{
                        temp->next = head;
                        temp = head;
                    }
                }
                head = head->next;
            }
            return dummy->next;
        }
    };