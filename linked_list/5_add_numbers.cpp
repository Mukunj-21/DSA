// Problem: https://leetcode.com/problems/add-two-numbers/

// mera tarika tha ki har list se pehle number bana lo aur fir use add karke same tarike se new list bana ke return krdo 

// optimal tarika hai ki har list se ek ek number lete jao aur carry ko bhi check karte jao agar carry hai to usko bhi add karlo
// aur fir jo sum bana usko saath saath list me append bhi karte jao 

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



// class Solution {
// public:
//     long long num(ListNode* l1){
//         ListNode* temp = l1;
//         long long ans = 0 , count = 0;
//         while(temp){
//             ans = ans+(temp->val)*pow(10,count);
//             temp = temp->next;
//             count++;
//         }
//         cout<<ans<<endl;
//         return ans;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         long long ans = num(l1)+num(l2);
//         ListNode* sum = new ListNode(ans%10);
//         ans=ans/10;
//         ListNode* temp = sum;
//         while(ans){
//             temp->next = new ListNode(ans%10);
//             temp = temp->next;
//             ans = ans/10;
//         }
//         return sum;
//     }
// };


class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* temp = dummy;
            int carry = 0;
            while(l1||l2||carry){
                int sum = carry;
                if(l1){
                    sum += l1->val;
                    l1=l1->next;
                }
                if(l2){
                    sum += l2->val;
                    l2=l2->next;
                }
                carry = sum/10;
                temp->next = new ListNode(sum%10);
                temp = temp->next;
            }
            // ListNode* ans = dummy->next;
            // delete dummy;
            return dummy->next;
        }
    };
    
    
    