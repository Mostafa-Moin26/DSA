// Problem link ------>
https://www.naukri.com/code360/problems/find-x-raised-to-power-n-_626560?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ------>

double compute(double x, long long n, double ans) {

  if (n == 1) return ans * x;

  if (n & 1) {
    return compute(x, n - 1, ans * x);
  }
  return compute(x * x, n / 2, ans);
}

double myPow(double x, int n) {
  // Write Your Code Here
  if (n == 0) return 1.0;
  
  long long num = (n < 0) ? -1 * n : n;

  double ans = compute(x, num, 1.0);


  return n < 0 ? 1.0 / ans : ans;
}