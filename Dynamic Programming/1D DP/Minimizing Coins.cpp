#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI 3.141592653589793238462
#define Mostafa         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define w(x)            int x;cin>>x;while(x--)
#define int              long long
#define pb              push_back
#define ff              first
#define ss              second
#define ps(x,y)         fixed<<setprecision(y)<<x
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)

// Memoization
int compute(vector<int>& coins, int sum, vector<int>& dp) {

    if (sum == 0) return 0;

    if (dp[sum] != -1) return dp[sum];

    int best = INT_MAX;

    for (int i = 0; i < coins.size(); i++) {

        if (sum - coins[i] >= 0) {
            best = min(best, 1 + compute(coins, sum - coins[i], dp));            
        }
 
    }

    return dp[sum] = best;
}
signed main() {
    Mostafa

    // https://cses.fi/problemset/task/1634/

    int n, k; cin >> n >> k;
    vector<int> coins(n);
    // vector<int> dp(k + 1, -1);
    vector<int> dp(k + 1, INT_MAX);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // int ans = compute(coins, k, dp);

    // if (ans >= INT_MAX) {
    //     cout << -1 << endl;
    // } else {
    //     cout << ans << endl;
    // }

    // Tabulation
    dp[0] = 0;

    for (int s = 1; s <= k; s++) {
        for (int c : coins) {
            if (s - c >= 0) {
                dp[s] = min(dp[s], dp[s - c] + 1);
            }
        }
    }

    cout << (dp[k] >= INT_MAX ? -1 : dp[k]) << endl;
    return 0;
}