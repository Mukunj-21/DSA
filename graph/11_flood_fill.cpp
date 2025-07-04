//Problem : https://leetcode.com/problems/flood-fill/

// simple hai dfs me call krdo prev value dedo , nayi value dedo aur agar prev value se match hoti hai to dfs call krdo for all directions


class Solution {
    public:
        vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}};
        void dfs(vector<vector<int>>& image, int sr, int sc, int color , int prev){
            int m = image.size() , n = image[0].size();
            image[sr][sc] = color;
            for(auto d:directions){
                int nrow = sr + d[0] , ncol = sc + d[1];
                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && image[nrow][ncol] == prev)
                    dfs(image , nrow , ncol , color , prev);
                else
                    continue;
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int prev = image[sr][sc];
            if(prev != color)
                dfs(image , sr , sc , color , prev);
            return image;
        }
    };