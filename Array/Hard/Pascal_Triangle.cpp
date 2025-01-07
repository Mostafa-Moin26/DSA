// Problem Link ---->
https://leetcode.com/problems/pascals-triangle/

// Three types of questions might be ask

// (1)   Given R and C, Find the element at that place
// (2)   Print any nth row in the pascal triangle
// (3)   print the entire pascal triangle

// Solutions ---->

// (1)  Given R and C, Find the element at that place
// Formula :  R-1
//               C
//                C-1
// We Know,    nCr =  n! / r! x (n - r)!
// Code
// long long nCr(int N, int R) {

//     long long res = 1;

//     for (int i = 0; i < N; i++) {
//         res = res * (N - i);
//         res = res / (i + 1);
//     }

//     return res;
// }


// (2) Print any nth row int the pascal triangle
// Formula :   ans * ((row - col) / col)

// code : 
// void printNthRow(int n) {

//     int ans = 1;
//     cout << ans << " ";

//     for (int i = 1; i < n; i++) {
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout << ans << "  ";
//     }
// }

// (3)  print the entire pascal triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> mat;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            // int ans = 1;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(mat[i-1][j-1] + mat[i-1][j]);
                    // ans = ans * (i - j + 1);
                    // ans = ans / j;
                    // row.push_back(ans);
                }
            }
            mat.push_back(row);
        }
        return mat;
    }
};