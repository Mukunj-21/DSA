// Problem: https://leetcode.com/problems/find-the-duplicate-number/

// Normal approach se koi bhi krlega constant space aur linear time mein karna hai to linked list waali 
// 2 pointer technique use karni padegi , slow aur fast ko do while loop se chalao jab tk same ni hote hai
// ab fast ko 0 se start karo aur slow ko jahan pe fast khada hai wahi se chalao jab tk dono same ni hote 
// kyuki pehle humne pta kra tha ki haan cycle hai exact repeated element nhi mila tha

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int slow = nums[0];
            int fast = nums[0];
            do{
                slow = nums[slow];
                fast = nums[nums[fast]];
            }while(slow!=fast);
            fast = nums[0];
            while(slow!=fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    };