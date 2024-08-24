// Problem link ------>
https://www.naukri.com/code360/problems/factorial-numbers-not-greater-than-n_8365435?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ------>
long long factorial(long long n) {

    if (n == 0 || n == 1) return 1;

    return n * factorial(n - 1);
}

void compute(long long i, long long num, vector<long long>& a) {
    long long res = factorial(i);

    if (res > num) return;

    a.push_back(res);
    compute(i + 1, num, a);
}
vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> ans;
    compute(1, n, ans);

    return ans;
}



