// Problem link ---->
https://leetcode.com/problems/toeplitz-matrix/description/

// Solutions --->

// My code
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int el, r, c;

        for (int i = 0; i < cols; i++) {
            el = matrix[0][i];
            r = 0; 
            c = i;

            while (r < rows && c < cols) {
                if (matrix[r][c] != el) {
                    return false;
                }
                r++, c++;
            }
        }

        for (int i = 1; i < rows; i++) {
            el = matrix[i][0];
            r = i;
            c = 0;
            
            while (r < rows && c < cols) {
                if (matrix[r][c] != el) {
                    return false;
                }
                r++, c++;
            }
        }

        return true;
        
    }
};

// Optimized code
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols - 1; j++) {
                if (matrix[i - 1][j] != matrix[i][j + 1]) {
                    return false;
                }
            }
        }

        return true;
        
    }
};