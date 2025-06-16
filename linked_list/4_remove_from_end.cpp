//Problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// 2 tarike hai 
// pehle ya to count karlo total nodes ab agar ye count n ke equal hai to head ko hi nikal do 
// fir jis node ko remove karna hai vaha tak jaake fir next ke andar uska bhi next daldo 


// dusra tarika hai ki ek fast aur slow pointer banao ab last se jonse node hatani hai fast ko utna aage lejao 
// ab slow aur fast ko next krdo jab tak fast khtm na hojaye fir slow ke next me uska bhi next daaldo hogya kaa, 

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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            // ListNode *temp = head;
            // int count = 0;
            // while(temp){
            //     temp=temp->next;
            //     count++;
            // }
            // if(n==count){
            //     ListNode* remove = head;
            //     head = head->next;
            //     delete remove;
            //     return head;
            // }
            // temp = head;
            // for(int i=0;i<count-n-1;i++)
            //     temp = temp->next;
            
            // ListNode* remove = temp->next;
            // temp->next = temp->next->next;
            // delete remove;
            // return head;
    
    
            ListNode* temp = new ListNode(0,head);
            ListNode* fast = temp;
            ListNode* slow = temp;
            for(int i=0;i<n;i++)
                fast = fast->next;
            while(fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = slow->next->next;
            return temp->next;
        }
    };