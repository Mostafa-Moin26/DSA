// Problem link ----->
https://leetcode.com/problems/expression-add-operators/

// Solution ----->
class Solution {
public:
    
    void compute(string num, int index, int target, string path, long long value, long long last, vector<string>& res) {

        if (index == num.size()) {
            if (value == target) res.push_back(path);
            return;
        }

        for (int i = index; i < num.size(); i++) {

            if (i > index && num[index] == '0') break;

            string currStr = num.substr(index, i - index + 1);
            long curr = stol(currStr);

            if (index == 0) {
                compute(num, i + 1, target, currStr, curr, curr, res);
            } else {
                compute(num, i + 1, target, path + "+" + currStr, value + curr, curr, res);
                compute(num, i + 1, target, path + "-" + currStr, value - curr, -curr, res);
                compute(num, i + 1, target, path + "*" + currStr, value - last + last * curr, last * curr, res);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;

        compute(num, 0, target, "", 0, 0, res);

        return res;
    }
};