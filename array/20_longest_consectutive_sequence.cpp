// Problem : https://leetcode.com/problems/longest-consecutive-sequence/description/

// sort krlo array ko fir count krte jao kitne numbers consecutively aa rhe hai and skip the duplicates

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            sort(nums.begin() , nums.end());
            int count = 1;
            int ans = 1;
            int n = nums.size();
            if(n==0)
                return 0;
            for(int i=1;i<n;i++){
                if(nums[i]==nums[i-1])
                    continue;
                if(nums[i]==nums[i-1]+1)
                    count++;
                else
                    count = 1;
                ans = max(ans , count);
                
            }
            return ans;
        }
    };