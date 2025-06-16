//Problem : https://leetcode.com/problems/merge-two-sorted-lists/

// agar koi ek list khali h to dusri return kardo then initially let merge me list1 daal do fir ab check karlo
// agar list2 ki value list 1 se choti hai to merge me list2 dalke next krdo list2 ko hi varna list1 hi next hojaegi
// and ek merge ka temp banalo taaki usko aage jodte jaye ab while loop chala jab tk koi ek khaali ni hojati to fir
// ab hum same upar waali condition hi dalenge ki jiski bhi value choti hogi usko add krdenge varna dusre ko 
// ab jab koi bhi ek khali hua to temp ke next me bachi hui puri list daaldo aur return merge ko krdo 

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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(!list1)
                return list2;
            if(!list2)
                return list1;
            ListNode* merge = list1;
            if(list1->val > list2->val){
                merge = list2;
                list2 = list2->next;
            }
            else
                list1 = list1->next;
            ListNode* temp = merge;
            while(list1 && list2){
                if(list1->val > list2->val){
                    temp->next = list2;
                    list2 = list2->next;
                }
                else{
                    temp->next = list1;
                    list1 = list1->next;
                }
                temp = temp->next;
            }
            if(!list1)
                temp->next = list2;
            else
                temp->next = list1;
            return merge;
        }
    };