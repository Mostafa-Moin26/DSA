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

/*       N = 3

          ""
        /    \
       0       1       <-- Level 1 (1st character)
      / \       \
     0   1       0     <-- Level 2 (2nd character)
    / \   \     / \
   0   1   0   0   1   <-- Level 3 (3rd character)

Root: ""
|
|-- "0" (Add '0')
|   |
|   |-- "00" (Add '0')
|   |   |
|   |   |-- "000" ✅ (Add '0')
|   |   |-- "001" ✅ (Add '1', last was '0')
|   |
|   |-- "01" (Add '1', last was '0')
|       |
|       |-- "010" ✅ (Add '0', last was '1')
|
|-- "1" (Add '1', last was '0')
    |
    |-- "10" (Add '0', last was '1')
        |
        |-- "100" ✅ (Add '0')
        |-- "101" ✅ (Add '1', last was '0')


Visual Explanation:
1.Root Node ("")

  -- Choices: Add '0' or '1' (since no previous character).

2.Branch 1: Adding '0' --> "0"

  -- Sub-branch 1: Add '0' --> "00"

        Can add '0' --> "000" ✅ (valid string, length=3)

        Can add '1' --> "001" ✅ (valid, no consecutive '1's)

  -- Sub-branch 2: Add '1' --> "01"

       Can only add '0' (last was '1') --> "010" ✅

3.Branch 2: Adding '1' --> "1"

  -- Can only add '0' (last was '1') --> "10"

     Sub-branch 1: Add '0' --> "100" ✅

     Sub-branch 2: Add '1' --> "101" ✅ (last was '0')


Final Valid Strings (Leaf Nodes):
"000"

"001"

"010"

"100"

"101"
*/