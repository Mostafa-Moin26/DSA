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

// Memoization function
int compute(int n, int sum, vector<int>& dp) {

    if (sum == n) return 1;
    if (sum > n) return 0;

    if (dp[sum] != -1) return dp[sum];

    int ways = 0;

    for (int dice = 1; dice <= 6; dice++) {

        ways = (ways + compute(n, sum + dice, dp)) % MOD;
    }

    return dp[sum] = ways;
}
signed main() {
    Mostafa

    int n; cin >> n;
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int dice = 1; dice <= 6; dice++) {

            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}