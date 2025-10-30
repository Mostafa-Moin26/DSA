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

int compute(vector<int>& coins, int x, vector<int>& dp) {

    if (x == 0) {
        return 1;
    }
    if (x < 0) return 0;

    if (dp[x] != -1) return dp[x];
    int cnt = 0;
    for (int i = 0; i < coins.size(); i++) {

        cnt = (cnt + compute(coins, x - coins[i], dp)) % MOD;
    }

    return dp[x] = cnt;

}
signed main() {
    Mostafa

   // https://cses.fi/problemset/task/1635/
    
    int n, x; cin >> n >> x;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // vector<int> dp(x + 1, -1);
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    int cnt = 0;

    for (int s = 1; s <= x; s++) {
        for (int c : coins) {

            if (s - c >= 0) {
                dp[s] = (dp[s] + dp[s - c]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    // cout << compute(coins, x, dp) << endl; 
    return 0;
}