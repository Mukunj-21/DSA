//Problem link: https://leetcode.com/problems/minimum-operations-to-make-xor-of-all-elements-equal-to-k/

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int temp=0;
            for(auto num:nums)
                temp ^= num;
            temp ^= k;
            int count = 0;
            while(temp){
                count += (temp & 1); 
                temp >>= 1;
            }
            return count;
        }
    };