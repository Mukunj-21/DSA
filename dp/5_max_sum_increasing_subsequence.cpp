class Solution {
    public:
      int solve(vector<int> &arr , int ind , int prev){
          if(ind<0)
              return 0;
          int take = INT_MIN;
          if(arr[ind]<arr[prev] || prev==-1)
              take = arr[ind] + solve(arr , ind-1 , ind);
          int leave = 0 + solve(arr , ind-1 , ind);
          return max(take , leave);
      }
      
      int solveMem(vector<int> &arr , int ind , int prev , vector<vector<int>> &dp){
              if(ind == arr.size())
                  return 0;
              if(dp[ind][prev+1]!=-1)
                  return dp[ind][prev+1];
              int take = 0;
              if(prev == -1 || arr[ind]>arr[prev])
                  take = arr[ind] + solveMem(arr , ind+1 , ind , dp);
              int leave = solveMem(arr , ind+1 , prev , dp);
              return dp[ind][prev+1] = max(take , leave);
      }
      
      
      
      int maxSumIS(vector<int>& arr) {
          int n = arr.size();
          // return solve(arr , n-1 , -1);
          
          vector<vector<int>> dp (n,vector<int>(n+1,-1));
          return solveMem(arr , 0 , -1 , dp);
      }
  };