// Problem link ---->
https://www.naukri.com/code360/problems/allocate-books_1090540?interviewProblemRedirection=true&search=Allocate%20books&attempt_status=COMPLETED

// Solution ---->
long long func(vector<int> &arr, int pages) {

    int std = 1;
    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {

        if (sum + arr[i] <= pages) {
            sum += arr[i];
        } else {
            std++;
            sum = arr[i];
        }
    }

    return std;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.

    if (m > n) {
        return -1;
    }
    
    int low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        if (func(arr, mid) <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}