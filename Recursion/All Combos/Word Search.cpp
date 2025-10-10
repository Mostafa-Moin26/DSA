// Problem link --->
https://leetcode.com/problems/word-search/description/


// Solution ---->
class Solution {
public:
    
    bool search(int i, int j, int index, string word, vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();
        
        if (index == word.size()) {
            return true;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        if (search(i + 1, j, index + 1, word, board) || search(i - 1, j, index + 1, word, board) ||
            search(i, j + 1, index + 1, word, board) || search(i, j - 1, index + 1, word, board)) {
                return true;
            }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (search(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};