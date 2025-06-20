// Problem: https://leetcode.com/problems/edit-distance/

// 4 cases hai total first is ki dono words ke character same hai to hume koi edit nahi karna to 0 add krke return krdo 
// else baaki cases me ya to delete hoga add hoga ya replace hoga to 1 add krke min of baaki 3 cases return krdo

class Solution {
    public:
        int solve(string word1 , string word2 , int n1 , int n2){
            if(n1<0)
                return n2+1;
            if(n2<0)
                return n1+1;
            if(word1[n1]==word2[n2])
                return 0 + solve(word1 , word2 , n1-1,n2-1);
            return 1 + min(solve(word1 , word2 , n1-1,n2),min(solve(word1 , word2 , n1,n2-1),solve(word1 , word2 , n1-1,n2-1)));
        }
    
        int solveMem(string word1 , string word2 , int n1 , int n2 , vector<vector<int>> &dp){
            if(n1<0)
                return n2+1;
            if(n2<0)
                return n1+1;
            if(dp[n1][n2]!=-1)
                return dp[n1][n2];
            if(word1[n1]==word2[n2])
                return dp[n1][n2] = 0 + solveMem(word1 , word2 , n1-1,n2-1,dp);
            return dp[n1][n2] = 1 + min(solveMem(word1 , word2 , n1-1,n2,dp),min(solveMem(word1 , word2 , n1,n2-1,dp),solveMem(word1 , word2 , n1-1,n2-1,dp)));
        }
    
        int solveTab(string word1 , string word2 , int n1 , int n2 , vector<vector<int>> &dp){
            if(n1<0)
                return n2+1;
            if(n2<0)
                return n1+1;
            if(dp[n1][n2]!=-1)
                return dp[n1][n2];
            if(word1[n1]==word2[n2])
                return dp[n1][n2] = 0 + solveMem(word1 , word2 , n1-1,n2-1,dp);
            return dp[n1][n2] = 1 + min(solveMem(word1 , word2 , n1-1,n2,dp),min(solveMem(word1 , word2 , n1,n2-1,dp),solveMem(word1 , word2 , n1-1,n2-1,dp)));
        }
    
        int minDistance(string word1, string word2) {
            int n1 = word1.size() , n2 = word2.size();
            // return solve(word1 , word2 , n1-1 , n2-1);
    
            vector<vector<int>> dp(n1,vector<int>(n2,-1));
            return solveMem(word1 , word2 , n1-1 , n2-1 , dp);
        }
    };