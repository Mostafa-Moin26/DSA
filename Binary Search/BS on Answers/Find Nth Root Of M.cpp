// Problem link ---->
https://www.naukri.com/code360/problems/nth-root-of-m_1062679?interviewProblemRedirection=true&search=Find%20Nth&leftPanelTabValue=PROBLEM

// Solution --->
int NthRoot(int n, int m) {
  // Write your code here.

  int low = 1, high = m;

  while (low <= high) {

    int mid = low + (high - low) / 2;

    if (pow(mid, n) == m) {
      return mid;
    }

    if (pow(mid, n) > m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}