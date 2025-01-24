// Problem link ---->
https://www.naukri.com/code360/problems/count-subarrays-with-given-xor_1115652?interviewProblemRedirection=true&attempt_status=COMPLETED

// Solutions ---->

// Brute force
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum ^= arr[j];

            if (sum == x) ans++;
        }
    }

    return ans;
}

// Optimal
#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int k)
{
    //    Write your code here.
    int n = arr.size();
    int xr = 0;
    map<int, int> mp;
    mp[xr]++;    // (0, 1)
    int cnt = 0;

    for (int i = 0; i < n; i++) {

        xr ^= arr[i];

        int x = xr ^ k;
        cnt += mp[x];

        mp[xr]++;
    }

    return cnt;
}
