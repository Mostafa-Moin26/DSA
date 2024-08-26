// Problem link ------>
https://www.naukri.com/code360/problems/print-fibonacci-series_7421617?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ------>
// this will give TLE in the big test case
int fibonacci(int n) {

    if (n <= 1) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.

    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        ans.push_back(fibonacci(i));
    }

    return ans;
}

// here optimize version using dp 

int dp[46];
int fibonacci(int n) {

    if (n <= 1) return n;

    if (dp[n] != 0) return dp[n];

    int res = fibonacci(n - 1) + fibonacci(n - 2);
    dp[n] = res;

    return res;
}

vector<int> generateFibonacciNumbers(int n) {
    // Write your code here.
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        ans.push_back(fibonacci(i));
    }

    return ans;
}
