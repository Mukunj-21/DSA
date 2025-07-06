//Problem : https://leetcode.com/problems/word-search/description/

// simple dfs use karo answer aa jaega

class Solution {
    public:
        int n, m;
        bool dfs(vector<vector<char>>& board, string& word, int ind, int i, int j) {
            if (ind == word.size())
            return true;
    
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[ind])
                return false;
    
            char temp = board[i][j];
            board[i][j] = '#';
    
            int r[] = {0 , 0 , 1 , -1};
            int c[] = {1 , -1 , 0 , 0};
            for (int k = 0 ; k < 4 ; k++) {
                int row = i + r[k] , col = j + c[k];
                if (dfs(board, word, ind + 1, row, col))
                    return true;
            }
    
            board[i][j] = temp;
            return false;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            m = board.size();
            n = board[0].size();
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0]) {
                        if (dfs(board, word, 0, i, j))
                            return true;
                    }
                }
            }
            return false;
        }
    };