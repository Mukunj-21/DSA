//Problem: https://leetcode.com/problems/longest-common-subsequence/

// last digit se start karo agar dono characters same aagye to dono me 1 minus krke compare kro firse aur saath saath count bhi +1 hoga
// agar same nahi aagye to dono me se kisi ek ko minus krke compare kro aur max lelo dono me se

class Solution {
    public:
        int solve(string text1 , string text2 ,int ind1 , int ind2){
            if(ind1<0||ind2<0)
                return 0;
            if(text1[ind1]==text2[ind2])
                return 1+solve(text1 , text2 , ind1-1 , ind2-1);
            return 0 + max(solve(text1,text2,ind1-1,ind2),solve(text1,text2,ind1,ind2-1));
        }
    
        int solveMem(string text1 , string text2 ,int ind1 , int ind2, vector<vector<int>> &dp){
            if(ind1<0||ind2<0)
                return 0;
            if(dp[ind1][ind2]!=-1)
                return dp[ind1][ind2];
            if(text1[ind1]==text2[ind2])
                return dp[ind1][ind2] = 1+solveMem(text1 , text2 , ind1-1 , ind2-1,dp);
            return dp[ind1][ind2] = max(solveMem(text1,text2,ind1-1,ind2,dp),solveMem(text1,text2,ind1,ind2-1,dp));
        }
    
        int solveTab(string text1 , string text2){
            int n1 = text1.size() , n2 = text2.size();
            vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
            for(int i=0;i<n1;i++)
                dp[i][0] = 0;
            for(int i=0;i<n2;i++)
                dp[0][i] = 0;
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(text1[i-1]==text2[j-1])
                        dp[i][j] = 1 + dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[n1][n2];
        }
    
        int solveSpace(string text1 , string text2){
            int n1 = text1.size() , n2 = text2.size();
            vector<int> prev(n2+1,0) , curr(n2+1,0);
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(text1[i-1]==text2[j-1])
                        curr[j] = 1 + prev[j-1];
                    else
                        curr[j] = max(prev[j],curr[j-1]);
                }
                prev = curr;
            }
            return prev[n2];
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            // int n1 = text1.size() , n2 = text2.size();
            // return solve(text1,text2,n1-1,n2-1);
    
            // vector<vector<int>> dp(n1,vector<int>(n2,-1));
            // return solveMem(text1,text2,n1-1,n2-1,dp);
    
            // return solveTab(text1 , text2);
    
            return solveSpace(text1 , text2);
        }
    };