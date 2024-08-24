// Problem link ------>
https://www.naukri.com/code360/problems/check-palindrome-recursive_624386?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTabValue=PROBLEM

// Solutions ------>
bool isPalindrome(string& str) {
    // Write your code here.

    if (str.size() <= 1) return true;

    if (str.front() != str.back()) return false;

    str = str.substr(1, str.size() - 2);

    return isPalindrome(str);
}



