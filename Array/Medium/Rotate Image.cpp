// Problem link ----->
https://leetcode.com/problems/rotate-image/description/

// solutions ----->
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        vector<vector<int>> mat = matrix;
        int n = matrix.size();
        int k;
        for (int i = 0; i < n; ++i) {
            for (int j = 0,k = n - 1; j < n; ++j, --k) {
                matrix[i][j] = mat[k][i];
            }
        }
    }
};

// little bit optimize
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> tmp = matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = tmp[n - j - 1][i];
            }
        }
    }
};

// not using another vector
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        reverse(matrix.begin(), matrix.end());

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// common method for rotating matrix
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first swap the symmetry, then reverse up to down
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
    reverse(matrix.begin(), matrix.end());
}