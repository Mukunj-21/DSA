//Problem: https://leetcode.com/problems/jump-game/

// ulta jaane ki socho , initially n is the last index, if we can reach n from 0 then return true

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n = nums.size() - 1;
            for(int i = nums.size()-2;i>=0;i--)
                if(i+nums[i] >= n)
                    n = i;
            return n==0;
        }
    };