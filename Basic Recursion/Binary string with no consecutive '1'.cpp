// Problem Link ----->
https://www.naukri.com/code360/problems/binary-strings-with-no-consecutive-1s_893001?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ---->

void solve(int n, vector<string>& ans, char lastChar, string s) {

    if (s.size() == n) {
        ans.push_back(s);
        return;
    }

    solve(n, ans, '0', s + '0');

    if (lastChar != '1') {
        solve(n, ans, '1', s + '1');
    }
}

vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;

    solve(N, ans, '0', "");

    return ans;
}
