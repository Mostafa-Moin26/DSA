// Problem link ---->
https://www.naukri.com/code360/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

// Solution ---->
#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.    
    int ans = -1, minEl = INT_MAX;
    int low = 0, high = arr.size() - 1;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid]) {
            if (minEl > arr[low]) {
                minEl = arr[low];
                ans = low;
            }
            low = mid + 1;
        } else {
            if (minEl > arr[mid]) {
                minEl = arr[mid];
                ans = mid;
            }
            high = mid - 1;
        }
    }

    return ans;
}