// Problem link ---->
https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?interviewProblemRedirection=true&search=painter&leftPanelTabValue=PROBLEM

// Solution ---->
long long func(vector<int> &boards, long long maxUnit) {
    int painters = 1;
    long long sum = 0;

    for (int i = 0; i < boards.size(); i++) {

        if (sum + boards[i] <= maxUnit) {
            sum += boards[i];
        } else {
            painters++;
            sum = boards[i];
        }
    }

    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (func(boards, mid) <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}