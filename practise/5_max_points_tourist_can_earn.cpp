// Problem: https://leetcode.com/problems/max-points-a-tourist-can-earn/description/

class Solution {
    public:
        int solve(int day , int curr , int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore){
            if(day==k)
                return 0;
            int ans = 0;
            ans = stayScore[day][curr] + solve(day+1 , curr , n , k , stayScore , travelScore);
            for(int next=0 ; next<n ; next++){
                if(curr!=next){
                    int total = travelScore[curr][next] + solve(day+1,next,n,k,stayScore,travelScore);
                    ans = max(ans , total);
                }
            }
            return ans;
        }
    
        int solveMem(int day , int curr , int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore , vector<vector<int>> &dp){
            if(day==k)
                return 0;
            if(dp[day][curr]!=-1)
                return dp[day][curr];
            int ans = 0;
            ans = stayScore[day][curr] + solveMem(day+1 , curr , n , k , stayScore , travelScore , dp);
            for(int next=0 ; next<n ; next++){
                if(curr!=next){
                    int total = travelScore[curr][next] + solveMem(day+1 , next , n , k , stayScore , travelScore , dp);
                    ans = max(ans , total);
                }
            }
            return dp[day][curr] = ans;
        }
    
        int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
            int ans = 0;
            vector<vector<int>> dp(k,vector<int>(n,-1));
            // for(int start=0 ; start<n ; start++)
            //     ans = max(ans , solve(0 , start , n , k , stayScore , travelScore));
    
            for(int start=0 ; start<n ; start++)
                ans = max(ans , solveMem(0 , start , n , k , stayScore , travelScore , dp));
            return ans;
            
        }
    };