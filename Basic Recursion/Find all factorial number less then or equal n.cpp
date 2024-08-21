// Problem Link  ------->
https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1


// Solution ------->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long fact(long long n) {
        if (n == 1) return 1;
        
        return n * fact(n - 1);
    }
    
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long> ans;
        
        int i = 1;
        
        while (fact(i) <= n) {
            ans.push_back(fact(i));
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends