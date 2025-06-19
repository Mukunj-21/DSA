//Problem: https://leetcode.com/problems/longest-increasing-subsequence/

// recursively dekhte jao agar value pichli taken value se badi hai to lelo otherwise leave and return max(take,leave)
// aur jab koi bhi value li hai to usme 1 add kardo which defines ki haan 1 count increase hogya hamare subsequence ka

class Solution {
    public:
        int solve(vector<int> &nums , int ind , int prev){
            if(ind == nums.size())
                return 0;
            int take = 0;
            if(prev == -1 || nums[ind]>nums[prev])
                take = 1 + solve(nums , ind+1 , ind);
            int leave = solve(nums , ind+1 , prev);
            return max(take , leave);
        }
    
        int solveMem(vector<int> &nums , int ind , int prev , vector<vector<int>> &dp){
            if(ind == nums.size())
                return 0;
            if(dp[ind][prev+1]!=-1)
                return dp[ind][prev+1];
            int take = 0;
            if(prev == -1 || nums[ind]>nums[prev])
                take = 1 + solveMem(nums , ind+1 , ind , dp);
            int leave = solveMem(nums , ind+1 , prev , dp);
            return dp[ind][prev+1] = max(take , leave);
        }
    
        int lengthOfLIS(vector<int>& nums) {
            // return solve(nums , 0 , -1);
    
            int n = nums.size();
            vector<vector<int>> dp (n,vector<int>(n+1,-1));
            return solveMem(nums , 0 , -1 , dp);
        }
    };