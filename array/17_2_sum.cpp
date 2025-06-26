// Problem: https://leetcode.com/problems/two-sum/

// map banalo aur usme check karo ki target - nums[i] hai ya nahi agar hai to return kardo indices varna insert krdo nahi hai to

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> m;
            for(int i=0;i<nums.size();i++){
                int num = target-nums[i];
                if(m.count(num))
                    return {m[num] , i};
                m.insert({nums[i] , i});
            }
            return {};
        }
    };
    
    