// Problem link ----->
https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1

// Solution ------>
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        
        long long C = A;
        long long D = B;
        while (A != 0 && B != 0) {
            
            if (A > B) A = A % B;
            else B = B % A;
        }
        
        long long gcd, lcm;
        
        if (A == 0) gcd = B;
        else gcd = A;
        
        lcm = ( C / gcd) * D;
        
        vector<long long> res;
        res.push_back(lcm);
        res.push_back(gcd);
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends

// easy method to calculate gcd
class Solution {
  public:
  
    long long gcd(long long a, long long b) {
        if (b == 0) return a;
        
        return gcd(b, a % b);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here 
        vector<long long> ans;
        
        long long _gcd = gcd(A, B);
        long long lcm = A * ( B / _gcd);
        
        ans.push_back(lcm);
        ans.push_back(_gcd);
        
        return ans;
    }
};