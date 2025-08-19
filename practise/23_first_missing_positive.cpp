// Problem : https://leetcode.com/problems/first-missing-positive

class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            // unordered_set<int> s;
            // int n=nums.size();
            // for(int i=0;i<n;i++)
            //     s.insert(nums[i]);
            // int maxi = *max_element(nums.begin() , nums.end());
            // if(maxi <= 0)
            //     return 1;
            // for(int i=1;i<maxi;i++)
            //     if(!s.count(i)){
            //         return i;
            //     }
            // return maxi+1;
    
            int n = nums.size();
            for(int i=0;i<n;i++)
                while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                    swap(nums[i] , nums[nums[i]-1]);
            for(int i=0;i<n;i++)
                if(nums[i] != i+1)
                    return i+1;
            return n+1;
        }
    };