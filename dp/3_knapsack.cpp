//Problem : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// same recursion lgaenge take leave waala lekin agar weight se zyada ho to take nahi karna hai
// base case should be last index pe aagye ab agar ye bhi lene layak h to uski val return krdo varna 0 hi 

class Solution {
    public:
      int solve(vector<int> &val, vector<int> &wt,int W,int ind){
          if(ind==0){
              if(wt[0]<=W)
                  return val[0];
              return 0;
          }
          int take = INT_MIN;
          if(wt[ind]<=W)
              take = val[ind] + solve(val , wt , W-wt[ind] , ind-1);
          int leave = 0 + solve(val , wt , W , ind-1);
          return max(take,leave);
      }
      
      int solveMem(vector<int> &val, vector<int> &wt,int W,int ind,vector<vector<int>> &dp){
          if(ind==0){
              if(wt[0]<=W)
                  return val[0];
              return 0;
          }
          if(dp[ind][W]!=-1)
              return dp[ind][W];
          int take = INT_MIN;
          if(wt[ind]<=W)
              take = val[ind] + solveMem(val , wt , W-wt[ind] , ind-1,dp);
          int leave = 0 + solveMem(val , wt , W , ind-1,dp);
          return dp[ind][W] = max(take,leave);
      }
      
      int solveTab(vector<int> &val, vector<int> &wt,int W){
          int n = wt.size();
          vector<vector<int>> dp(n , vector<int>(W+1,0));
          for(int i=wt[0];i<=W;i++)
              dp[0][i] = val[0];
          for(int i=1;i<n;i++){
              for(int j=0;j<=W;j++){
                  int leave = dp[i-1][j];
                  int take=INT_MIN;
                  if(wt[i]<=j)
                      take = val[i] + dp[i-1][j-wt[i]];
                  dp[i][j] = max(take,leave);
              }
          }
          return dp[n-1][W];
      }
      
      int solveSpace(vector<int> &val, vector<int> &wt,int W){
          int n = wt.size();
          vector<int> prev(W+1,0) , curr(W+1,0);
          for(int i=wt[0];i<=W;i++)
              prev[i] = val[0];
          for(int i=1;i<n;i++){
              for(int j=0;j<=W;j++){
                  int leave = prev[j];
                  int take=INT_MIN;
                  if(wt[i]<=j)
                      take = val[i] + prev[j-wt[i]];
                  curr[j] = max(take,leave);
              }
              prev = curr;
          }
          return prev[W];
      }
      
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          int n = wt.size();
          
          // return solve(val,wt,W,n-1);
          
          // vector<vector<int>> dp(n , vector<int>(W+1,-1));
          // return solveMem(val,wt,W,n-1,dp);
          
          // return solveTab(val,wt,W);
          
          return solveSpace(val,wt,W);
      }
  };