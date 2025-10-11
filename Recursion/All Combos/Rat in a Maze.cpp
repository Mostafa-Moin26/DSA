// Problem link ---->
https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// Solution --->
class Solution {
  public:
    
    void compute(int row, int col, vector<vector<int>>& maze, vector<vector<int>>& vis, vector<string>& ans, string move) {
        int n = maze.size();
        if (row == n - 1 && col == n - 1) {
            ans.push_back(move);
            return;
        }
        
        // Down
        if (row + 1 < n && maze[row + 1][col] && !vis[row + 1][col]) {
            vis[row][col] = 1;
            compute(row + 1, col, maze, vis, ans, move + "D");
            vis[row][col] = 0;
        }
        // Left
        if (col - 1 >= 0 && maze[row][col - 1] && !vis[row][col - 1]) {
            vis[row][col] = 1;
            compute(row, col - 1, maze, vis, ans, move + "L");
            vis[row][col] = 0;
        }
        // Right
        if (col + 1 < n && maze[row][col + 1] && !vis[row][col + 1]) {
            vis[row][col] = 1;
            compute(row, col + 1, maze, vis, ans, move + "R");
            vis[row][col] = 0;
        }
        //Up
        if (row - 1 >= 0 && maze[row - 1][col] && !vis[row - 1][col]) {
            vis[row][col] = 1;
            compute(row - 1, col, maze, vis, ans, move + "U");
            vis[row][col] = 0;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        if (maze[0][0] == 1) {
            compute(0, 0, maze, vis, ans, "");
        }
        
        return ans;
        
    }
};