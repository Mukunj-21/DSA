// Problem: https://leetcode.com/problems/sudoku-solver/

class Solution {
    public:
        bool isValid(vector<vector<char>>& board , int num , int r , int c){
            for(int i=0;i<9;i++){
                if(board[r][i] == '0' + num)
                    return false;
            }
            for(int i=0;i<9;i++){
                if(board[i][c] == '0' + num)
                    return false;
            }
            int row = (r/3)*3 , col = (c/3)*3;
            for(int i=row;i<row+3;i++)
                for(int j=col;j<col+3;j++)
                    if(board[i][j] == '0' + num)
                        return false;
            return true;
        }
        bool solve(vector<vector<char>>& board , int row , int col){
            if(row == 9)
                return true;
            if(col == 9)
                return solve(board , row+1 , 0);
            if(board[row][col] != '.')
                return solve(board , row , col+1);
            for(int i=1;i<=9;i++){
                if(isValid(board , i , row , col)){
                    board[row][col] = '0' + i;
                    bool res = solve(board , row , col+1);
                    if(res)
                        return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        void solveSudoku(vector<vector<char>>& board) {
            solve(board, 0, 0);
        }
    };