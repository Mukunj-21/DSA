//Problem : https://leetcode.com/problems/linked-list-cycle/description/

// 2 pointers banalo slow and fast agar kisi bhi point pe slow == fast hojaye to loop hai list me else not
// while loop me condition lagaenge ki fast aur fast ka next dono null nahi hone chahiye varna null ka next nhi nikal paenge hum

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
        bool hasCycle(ListNode *head) {
            if(!head || !head->next)
                return false;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast)
                    return true;
            }
            return false;
        }
    };