//Problem : https://leetcode.com/problems/intersection-of-two-linked-lists/

// simply length nikal lo dono lists ki aur difference nikal lo jiski length badi hogi usko us difference se aage le jao
// then traverse both lists together and return the first node where they meet

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
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            // unordered_set<ListNode*> st;
            // while(!headA){
            //     st.insert(headA);
            //     headA = headA->next;
            // }
            // while(!headB){
            //     if(st.find(headB)!= st.end())
            //         return headB;
            //     headB = headB->next;
            // }
            // return NULL;
            ListNode* currA = headA;
            ListNode* currB = headB;
            int length1 = 0 , length2 = 0;
            while(currA){
                length1++;
                currA = currA->next;
            }
            while(currB){
                length2++;
                currB = currB->next;
            }
            int count = abs(length1-length2)+1;
            cout<<length1<<endl<<length2<<endl<<count<<endl;
            currA = headA ; currB = headB;
    
            if (length1 > length2) {
                int diff = length1 - length2;
                while (diff--) currA = currA->next;
            } 
            else {
                int diff = length2 - length1;
                while (diff--) currB = currB->next;
            }
    
            while (currA && currB) {
                if (currA == currB) return currA;
                currA = currA->next;
                currB = currB->next;
            }
            return NULL;
        }
    };