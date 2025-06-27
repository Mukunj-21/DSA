//Problem: https://leetcode.com/problems/minimum-path-sum/

// recursive approach se socho to agar 1 element tk aagya to vo element return krdo agar out of bound jaye to INT_MAX return krdo
// taaki us element ka contribution na ho phir up aur left se minimum lelo aur usme current element ka value add krdo

// for tabulation edge cases me yaani ki 1 row and 1 column ke andar grid ki value pehle se daal do taaki aage jaate hue 
// pichli minimum value ka use ho sake

class Solution {
    public:
        int solve(vector<vector<int>> &grid , int i , int j){
            if(i==0 && j==0)
                return grid[0][0];
            if(i<0 || j<0)
                return INT_MAX;
            int up = solve(grid , i-1 , j);
            int left = solve(grid , i , j-1);
            return grid[i][j] + min(left,up);
        }
    
        int solveMem(vector<vector<int>> &grid , int i , int j , vector<vector<int>>&dp){
            if(i==0 && j==0)
                return grid[0][0];
            if(i<0 || j<0)
                return INT_MAX;
            if(dp[i][j] != -1)
                return dp[i][j];
            int up = solveMem(grid , i-1 , j ,dp);
            int left = solveMem(grid , i , j-1 ,dp);
            return dp[i][j] =  grid[i][j] + min(left,up);
        }
    
        int solveTab(vector<vector<int>> &grid){
            int m = grid.size() , n = grid[0].size();
            vector<vector<int>>dp (m,vector<int>(n,0));
            dp[0][0] = grid[0][0];
            for(int i=1 ;i<m;i++)
                dp[i][0] = grid[i][0] + dp[i-1][0];
            for(int i=1 ;i<n;i++)
                dp[0][i] = grid[0][i] + dp[0][i-1];
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    dp[i][j] =  grid[i][j] + min(left,up);
                }
            }
            return dp[m-1][n-1];
        }
    
        int solveSpace(vector<vector<int>> &grid){
            int m = grid.size() , n = grid[0].size();
            vector<int>prev (n,0);
            vector<int>curr (n,0);
            prev[0] = grid[0][0];
    
            for(int i=1 ;i<n;i++)
                prev[i] = grid[0][i] + prev[i-1];
    
            for(int i=1;i<m;i++){
                curr[0] = grid[i][0] + prev[0];
                for(int j=1;j<n;j++){
                    int up = prev[j];
                    int left = curr[j-1];
                    curr[j] =  grid[i][j] + min(left,up);
                }
                prev = curr;
            }
            return prev[n-1];
        }
    
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size() , n = grid[0].size();
            // return solve(grid , m-1 , n-1);
    
            // vector<vector<int>>dp (m,vector<int>(n,-1));
            // return solveMem(grid , m-1 , n-1 , dp);
    
            // return solveTab(grid);
    
            return solveSpace(grid);
        }
    };