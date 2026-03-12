// Problem link ---->
https://leetcode.com/problems/spiral-matrix-ii/description/


// Solution ---->
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int num = 1;
        vector<vector<int>> res(n, vector<int> (n));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        while (left <= right && top <= bottom) {

            for (int i = left; i <= right; i++) {
                res[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res[i][right] = num++;
            }
            right--;

            if (top <= bottom) {
               for (int i = right; i >= left; i--) {
                res[bottom][i] = num++;
               } 
               bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = num++;
                }
                left++;
            }
        }

        return res;
    }
};


// Using direction vector
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));

        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        int r = 0, c = 0, dir = 0;

        for (int num = 1; num <= n * n; num++) {
            res[r][c] = num;

            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || res[nr][nc] != 0) {
                dir = (dir + 1) % 4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }

            r = nr;
            c = nc;
        }

        return res;
    }
};