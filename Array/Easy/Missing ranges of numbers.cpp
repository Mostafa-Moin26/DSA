// Problem link --->
https://www.geeksforgeeks.org/problems/missing-ranges-of-numbers1019/1

// Solutions --->

// my code for only if the array is not empty and does not contain duplicate value
class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &a, int lower, int upper) {
        // Code here
        
        vector<vector<int>> res;
        int n = a.size();
        
        if (lower < a[0]) {
            res.push_back({lower, a[0] - 1});
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1] - 1) {
                res.push_back({a[i] + 1, a[i + 1] - 1});
            }
        }
        
        if (upper > a[n - 1]) {
            res.push_back({a[n - 1] + 1, upper});
        }
        
        return res;
    }
};


// Optimized solution, work for empty array and duplicate elements
class Solution {
public:
    vector<vector<int>> missingRanges(vector<int> &a, int lower, int upper) {
        
        vector<vector<int>> res;
        int n = a.size();
        
        if (n == 0) {
            res.push_back({lower, upper});
            return res;
        }
        
        if (lower < a[0]) {
            res.push_back({lower, a[0] - 1});
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] - a[i] > 1) {
                res.push_back({a[i] + 1, a[i + 1] - 1});
            }
        }
        
        if (upper > a[n - 1]) {
            res.push_back({a[n - 1] + 1, upper});
        }
        
        return res;
    }
};

// More organized
class Solution {
public:
    vector<vector<int>> missingRanges(vector<int>& a, int lower, int upper) {
        
        vector<vector<int>> res;
        long prev = (long)lower - 1;
        
        for (int i = 0; i <= a.size(); i++) {
            
            long curr = (i == a.size()) ? (long)upper + 1 : a[i];
            
            if (curr - prev >= 2) {
                res.push_back({prev + 1, curr - 1});
            }
            
            prev = curr;
        }
        
        return res;
    }
};