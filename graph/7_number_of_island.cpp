//Problem : https://leetcode.com/problems/number-of-islands/description/

// Graph ke problem ki tarah socho like we don't have any paths or connectedness of nodes but we can consider all 1's connected 
// and 0's as not connected. So we can use DFS or BFS to find the number of islands.
// simply ek visited grid bhi banalo and then for loop se jo unvisited 1's milenge unpe dfs ya bfs call kar do
// dfs and bfs me unvisited 1's ke saath saath unke neighbours ko bhi visit karte jao 

class Solution {
    public:
        void bfs(int row , int col , vector<vector<int>> &visited , vector<vector<char>>& grid){
            visited[row][col] = 1;
            int m = grid.size() , n = grid[0].size();
            queue<pair<int,int>> q;
            q.push({row,col});
            while(!q.empty()){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                int rows[] = {-1 , 0 , +1 , 0};
                int cols[] = {0 , +1 , 0 , -1};
                for(int i=0;i<4;i++){
                    int nrow = row + rows[i];
                    int ncol = col + cols[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                    && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                        bfs(nrow , ncol , visited , grid);
                }
            }
        }
    
        void dfs(int row , int col , vector<vector<int>> &visited , 
                    vector<vector<char>>& grid){
            
            visited[row][col] = 1;
            int m = grid.size() , n = grid[0].size();
            int rows[] = {-1 , 0 , +1 , 0};
                int cols[] = {0 , +1 , 0 , -1};
                for(int i=0;i<4;i++){
                    int nrow = row + rows[i];
                    int ncol = col + cols[i];
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n 
                    && !visited[nrow][ncol] && grid[nrow][ncol] == '1')
                        dfs(nrow , ncol , visited , grid);
                }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int m = grid.size() , n = grid[0].size();
            vector<vector<int>> visited(m , vector<int> (n,0));
            int count = 0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(!visited[i][j] && grid[i][j] == '1'){
                        count++;
                        // bfs(i , j , visited , grid);
                        dfs(i , j , visited , grid);
                    }
                }
            }
            return count;
        }
    };