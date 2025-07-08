//Problem : https://leetcode.com/problems/rotting-oranges/description/

// dfs ki jagah isme bfs approach use krni pdegi kyuki ek time pe jitne bhi rotten oranges hai vo saare ek saath traverse krke
// oranges ko khrb krenge to jab jab koi orange rotten hoga tab tab usko queue me dalenge aur har queue ki 1 iteration ke liye 
// minutes ko add krte rahenge , ek hum fresh oranges ka bhi count rkhenge taaki agar last me fresh bach gya to -1 return krdenge

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int m = grid.size() , n = grid[0].size();
            int fresh = 0;
            queue<pair<int , int>> q;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(grid[i][j] == 2)
                        q.push({i,j});
                    else if(grid[i][j] == 1)
                        fresh++;
                }
            }
            if(fresh==0)
                return 0;
            int ans = -1;
            int r[] = {1 , -1 , 0 , 0};
            int c[] = { 0 , 0 , 1 , -1};
            while(!q.empty()){
                int s = q.size();
                ans++;
                for(int i=0 ; i<s ; i++){
                    auto [a,b] = q.front();
                    q.pop();
                    for(int d=0 ; d<4 ; d++){
                        int row = a + r[d] , col = b + c[d];
                        if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1){
                            grid[row][col] = 2;
                            q.push({row , col});
                            fresh--;
                        }
                    }
                }
            }
            return (fresh==0) ? ans : -1;
        }
    };