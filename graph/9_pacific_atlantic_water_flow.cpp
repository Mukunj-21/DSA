// Problem Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

// Left and Top border pe pacific ocean hai to hum us end se start krke aage har cell ko check karenge ki uski height jda hai ya nhi 
// agar jda hogi tabhi paani flow ho paega yaha tk aur if yes to hum true krde us cell ko ocean me
// similarly goes for atlantic ocean with right and bottom border and jitne cells dono me true hue unhe return karwa denge 

class Solution {
    public:
    
        void dfs(int i , int j , vector<vector<int>>& heights , vector<vector<bool>> &ocean){
            int m = heights.size() , n = heights[0].size();
            ocean[i][j] = true;
            vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto d:directions){
                int x = i+d[0] , y = j+d[1];
                if(x>=0 && x<m && y>=0 && y<n && !ocean[x][y] && heights[x][y] >= heights[i][j])
                    dfs(x , y , heights , ocean);
            }
        }
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            if(heights.empty())
                return {};
            int m = heights.size() , n = heights[0].size();
            vector<vector<bool>> pacific(m,vector<bool>(n,false));
            vector<vector<bool>> atlantic(m,vector<bool>(n,false));
            for(int i=0;i<m;i++){
                dfs(i , 0 , heights , pacific);
                dfs(i , n-1 , heights , atlantic);
            }
            for(int i=0;i<n;i++){
                dfs(0 , i , heights , pacific);
                dfs(m-1 , i , heights , atlantic);
            }
            vector<vector<int>> ans;
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    if(pacific[i][j] && atlantic[i][j])
                        ans.push_back({i,j});
            return ans;
        }
    };