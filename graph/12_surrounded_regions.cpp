// Problem : https://leetcode.com/problems/surrounded-regions/description/

// dfs approach socho to pehle saare boundary waale O ko T mein convert kar do aur fir at the end jitne O reh gye uhne X bana do 
// aur jitne T hain unhe vapis O bana do

class Solution {
    public:
        void dfs(vector<vector<char>>& board , int i , int j){
            int m = board.size() , n = board[0].size();
            if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
                return;
            board[i][j] = 'T';
            dfs(board , i+1 , j);
            dfs(board , i-1 , j);
            dfs(board , i , j+1);
            dfs(board , i , j-1);
        }
        void solve(vector<vector<char>>& board) {
            int m = board.size() , n = board[0].size();
            for(int i=0;i<m;i++){
                dfs(board , i , 0);
                dfs(board , i , n-1);
            }
            for(int i=0;i<n;i++){
                dfs(board , 0 , i);
                dfs(board , m-1 , i);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j] == 'O')
                        board[i][j] = 'X';
                    else if(board[i][j] == 'T')
                        board[i][j] = 'O';
                }
            }
        }
    };