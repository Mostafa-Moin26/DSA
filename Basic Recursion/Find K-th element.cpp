// Problem Link ----->
https://www.naukri.com/code360/problems/find-k-th-element_1214963?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ---->

#include <bits/stdc++.h> 

vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) return arr;

    vector<int> left, right;

    int mid = arr.size() / 2;

    for (int i = 0; i < mid; ++i) {
        left.push_back(arr[i]);
    }

    for (int i = mid; i < arr.size(); ++i) {
        right.push_back(arr[i]);
    }

    vector<int> sortedLeft = mergeSort(left);
    vector<int> sortedRight = mergeSort(right);

    int idx1, idx2; idx1 = idx2 = 0;
    vector<int> ans;

    for (int i = 0; i < arr.size(); ++i) {

        if (idx1 == sortedLeft.size()) {
            ans.push_back(sortedRight[idx2]);
            idx2++;
        } else if (idx2 == sortedRight.size()) {
            ans.push_back(sortedLeft[idx1]);
            idx1++;
        } else if (sortedLeft[idx1] < sortedRight[idx2]) {
            ans.push_back(sortedLeft[idx1]);
            idx1++;
        } else {
            ans.push_back(sortedRight[idx2]);
            idx2++;
        }
    }

    return ans;
}
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    // Write your code here.

    vector<int> arr;

    arr.assign(arr1.begin(), arr1.end());

    arr.insert(arr.end(), arr2.begin(), arr2.end());

    vector<int> ans = mergeSort(arr);

    return ans[k - 1];

}
