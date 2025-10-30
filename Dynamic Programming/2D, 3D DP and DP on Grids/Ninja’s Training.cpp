// Problem link ---->
https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM

// Solutions ---->
// Normal Recursion (will get TLE)
#include <vector>
#include <algorithm>

using namespace std;

int compute(int day, int last, vector<vector<int>>& points) {

    if (day == 0) {
        int mx = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                mx = max(mx, points[day][task]);
            }
        }
        return mx;
    }

    int mx = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {

            int point = points[day][task] + compute(day - 1, task, points);
            mx = max(mx, point);
        }
    }
    return mx;
}
int ninjaTraining(int n, vector<vector<int>> &points) {

    return compute(n - 1, 3, points, dp);
}

// Memoization
#include <vector>
#include <algorithm>

using namespace std;

int compute(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {

    if (day == 0) {
        int mx = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                mx = max(mx, points[day][task]);
            }
        }
        return mx;
    }

    if (dp[day][last] != -1) return dp[day][last];
    int mx = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {

            int point = points[day][task] + compute(day - 1, task, points, dp);
            mx = max(mx, point);
        }
    }
    return dp[day][last] = mx;
}
int ninjaTraining(int n, vector<vector<int>> &points) {

    vector<vector<int>> dp(n, vector<int>(4, -1));
    return compute(n - 1, 3, points, dp);
}


// Tabulation
#include <vector>
#include <algorithm>

using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {

    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            int mx = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    mx = max(mx, point);
                }
            }
            dp[day][last] = mx;
        }
    }

    return dp[n - 1][3];
}



