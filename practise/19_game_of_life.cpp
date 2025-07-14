//Problem : https://leetcode.com/problems/game-of-life/description/

class Solution {
    public:
        int count(vector<vector<int>>& board , int i , int j){
            int m = board.size() , n = board[0].size();
            int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1};
            int dy[] = {1 , -1 , 0 , 1 , -1 , 1 , -1 , 0};
            int ans = 0;
            for(int k=0;k<8;k++){
                int r = i+dx[k] , c = j + dy[k];
                if(r < m && r >= 0 && c < n && c >= 0 && board[r][c] == 1)
                    ans++;
            }
            return ans;
        }
        void gameOfLife(vector<vector<int>>& board) {
            vector<vector<int>> temp = board;
            int m = temp.size() , n = temp[0].size();
            for(int i=0;i<m;i++){
                for(int j=0 ; j<n;j++){
                    int ans = count(temp , i , j);
                    if(temp[i][j] == 1 && (ans < 2 || ans > 3))
                        board[i][j] = 0;
                    else if(temp[i][j] == 0 && ans ==3)
                        board[i][j] = 1;
                    else
                        continue;
                }
            }
        }
    };