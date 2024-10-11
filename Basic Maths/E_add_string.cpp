// Problem link ------>
https://leetcode.com/problems/add-strings/description/

// Solutions ----->
//my solutions🤣
class Solution {
public:
string addStrings(string num1, string num2)
{
	int curr = 0;
	string s = "";

	if (num1.size() < num2.size())
		swap(num1, num2);

	int n = num1.size();
	int m = num2.size();
	int j = m - 1;

	for (int i = n - 1; i >= 0; i--)
	{

		if (i < n - m)
		{
			if (curr)
			{
				if (num1[i] == '9') {
					s += '0';
					if (i == 0) s += '1';
                    curr = 1;
				}
				else {
                s += num1[i] + 1;
				curr = 0;
                }
			}
			else
			{
				s += num1[i];
			}
		}
		else
		{
			int num = (num1[i] - '0') + (num2[j] - '0');
			int dg = num % 10;
			if (num >= 10)
			{
				if (curr)
				{
					dg++;
					s += to_string(dg);
				}
				else
				{
					s += to_string(dg);
				}
				curr = 1;
			}
			else if (num == 9)
			{
				if (curr)
				{
					s += '0';
				}
				else
				{
					s += to_string(dg);
				}
			}
			else
			{
				if (curr) {
					dg++;
					s += to_string(dg);
				}
				else s += to_string(dg);
				curr = 0;
			}
			j--;
		}
	}
	if (n == m && curr) s += '1'; 
	reverse(s.begin(), s.end());
	return s;
}
};

// some optimization 
class Solution {
public:
string addStrings(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    if (num1.size() < num2.size())
		swap(num1, num2);

	int curr = 0;
	string ans = "";

    for (int i = 0; i < num1.size(); i++) {
        
        if (i >= num2.size()) {
            int sum = (num1[i] - '0') + curr;
            int dg = sum % 10;
            curr = sum / 10;
            ans += to_string(dg);
        } else {
            int sum = (num1[i] - '0') + (num2[i] - '0') + curr;
            int dg = sum % 10;
            curr = sum / 10;
            ans += to_string(dg);
        }
    }

    if (curr) ans += "1";
    
    reverse(ans.begin(), ans.end());

	return ans;
}
};

// optimized code inspired from Add binary problem solution
class Solution {
public:
    string addStrings(string num1, string num2) {

       string res = "";
       int carr = 0;
       int i = num1.size() - 1;
       int j = num2.size() - 1;

       while (i >= 0 || j >= 0 || carr) {
        int sum = carr;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        carr = sum / 10;

        if (carr) {
            res += (sum % 10) + '0';
        } else {
            res += sum + '0';
        }
       } 

       reverse(res.begin(), res.end());

       return res;
    }
};