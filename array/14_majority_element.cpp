// Problem: https://leetcode.com/problems/majority-element/

// simply socho agar koi major element hai jo half times atleast aa rha hai to jab vo aaega count badhate jao
// agar koi aur element aaya to count ko kam krte jao lekin agar count zero ho gaya to element ko change kr do
// which defines the majority element 

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0 , element;
            for(int i=0;i<nums.size();i++){
                if(!count)
                    element = nums[i];
                if(element == nums[i])
                    count++;
                else
                    count--;
            }
            return element;
        }
    };