//Problem : https://leetcode.com/problems/burst-balloons/

// nums ke begin aur end me 1 add krdo ab dp use krni pdegi ki left aur right se kaunse balloon ko burst krna hai

class Solution {
    public:
        int solve(vector<int>& arr , vector<vector<int>> &dp , int left , int right){
            if(left+1 == right)
                return 0;
            if(dp[left][right] != -1)
                return dp[left][right];
            int maxi = 0;
            for(int i=left+1;i<right;i++){
                int sum = arr[left]*arr[i]*arr[right];
                sum += solve(arr , dp , left , i);
                sum += solve(arr , dp , i , right);
                maxi = max(maxi , sum);
            }
            return dp[left][right] = maxi;
        }
    
        int solveTab(vector<int> &nums){
            nums.push_back(1);
            nums.insert(nums.begin(),1);
            int n = nums.size();
            vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
            for(int left = n-1 ; left>=0 ; left--){
                for(int right = 0 ; right<n ; right++){
                    if(left>right)
                        continue;
                    int maxi = 0;
                    for(int i=left+1 ; i<right ; i++){
                        maxi = max(maxi , nums[left]*nums[i]*nums[right]
                                         + dp[left][i] + dp[i][right] );
                    }
                    dp[left][right] = maxi;
                }
            }
            return dp[0][n-1];
        }
    
        int maxCoins(vector<int>& nums) {
            // int n = nums.size();
            // vector<int> arr(n+2 , 1);
            // vector<vector<int>> dp(n+2 , vector<int>(n+2,-1));
            // for(int i=0;i<n;i++)
            //     arr[i+1] = nums[i];
            // return solve(arr , dp , 0 , n+1);
    
            return solveTab(nums);
        }
    };