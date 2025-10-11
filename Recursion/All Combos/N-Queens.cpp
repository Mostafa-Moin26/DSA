// Problem link ---->
https://leetcode.com/problems/n-queens/ 

// Solution --->
class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int duprow = row;
        int dupcol = col;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--, col--;
        }

        row = duprow;
        col = dupcol;

        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }

        col = dupcol;

        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row++, col--;
        }
        return true;
    }
    void compute(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                compute(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {  
        vector<vector<string>> ans; 
        vector<string> board(n); 
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        } 
        compute(0, n, board, ans);

        return ans;
    }
};