// Problem link ---->
https : // leetcode.com/problems/valid-parentheses/

        // Solutions ---->
        class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        vector<char> v;

        for (int i = 0; i < n; i++)
        {

            if ((int)v.size() == 0)
                v.push_back(s[i]);

            else
            {
                char ch = v.back();
                if (ch == '(' && s[i] == ')')
                    v.pop_back();
                else if (ch == '{' && s[i] == '}')
                    v.pop_back();
                else if (ch == '[' && s[i] == ']')
                    v.pop_back();
                else
                    v.push_back(s[i]);
            }
        }
        if (v.size() == 0)
            return true;
        else
            return false;
    }
};

// using map and stack
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s)
        {
            if (mapping.find(c) == mapping.end())
            {
                stack.push(c);
            }
            else if (!stack.empty() && mapping[c] == stack.top())
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }

        return stack.empty();
    }
};

// using helper function and stack
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (char cur : s)
        {
            if (!st.empty())
            {
                char last = st.top();
                if (isPair(last, cur))
                {
                    st.pop();
                    continue;
                }
            }
            st.push(cur);
        }

        return st.empty();
    }

private:
    bool isPair(char last, char cur)
    {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};

/// My solution
class Solution
{
public:
    bool isValid(string s)
    {

        vector<char> vect;

        for (int i = 0; i < s.size(); i++)
        {
            char cur = s[i];

            if (vect.empty() || cur == '(' || cur == '{' || cur == '[')
            {
                vect.push_back(cur);
            }
            else
            {

                if (cur == ')' && vect.back() == '(')
                {
                    vect.pop_back();
                }
                else if (cur == '}' && vect.back() == '{')
                {
                    vect.pop_back();
                }
                else if (cur == ']' && vect.back() == '[')
                {
                    vect.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        return vect.empty();
    }
};