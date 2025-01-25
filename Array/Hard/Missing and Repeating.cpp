// Problem link ----->
https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating

// Solutions ---->
// My solution
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        long long n = arr.size(); 
        sort(arr.begin(), arr.end());
        long long a, b;
        long long sum = arr[0];
        
        for (int i = 1; i < n; i++) {
            sum += arr[i];
            if (arr[i] == arr[i - 1]) {
                b = arr[i];
                sum -= b;
            }
        }
        
        a = (n * (n + 1)) / 2 - sum;
        
        return {b, a};
    }
};

// using hash map
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        map<int, int> mp;
        int n = arr.size();
        int a, b;
        
        for (int i = 1; i <= n; i++) {
            mp[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        
        for (auto i : mp) {
            
            if (i.second == 0) a = i.first;
            if (i.second == 2) b = i.first;
        }
        
        return {b, a};
    }
};

// using hash array
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int a, b;
        int aa[n + 1] = {0};
        
        for (int i = 0; i < n; i++) {
            aa[arr[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            
            if (aa[i] == 0) a = i;
            if (aa[i] == 2) b = i;
        }
        
        
        return {b, a};
    }
};

// Optimal solution using math 
/*Let x = repeating
      Y = missing
Suppose we have an array = [1, 2, 1, 4, 5, 6] 
Now, we have to find x and y
S = (1 + 2 + 1 + 4 + 5 + 6)
SN = (1 + 2 + 3 + 4 + 5 + 6)
S – SN = -2
x – y = -2    -----> (i)
Again, 
S2 = (1^2 + 2^2 + 1^2 + 4^2 + 5^2 + 6^2)
S2N = (1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2)
S2 – S2N = -8
x^2 – y^2 = -8
(x – y) (x + y) = -8
x + y = 4    ------> (ii) 

x - y = - 2
x + y = 4
-------------
2x = 2
So x = 1 and y = 3
So repeated number is 1 and missing number is 3  */

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        // code here
        long long n = nums.size();
        long long S = 0, S2 = 0, SN, S2N;
        SN = (n * (n + 1)) / 2;
        S2N = (n * (n + 1) * ( 2 * n + 1)) / 6;

        for (int i = 0; i < n; i++) {
            S += nums[i];
            S2 += (long long)nums[i] * (long long)nums[i];
        }

        long long eq1 = S - SN;
        long long eq2 = S2 - S2N;
        eq2 = eq2 / eq1;

        long long repeatedNum = (eq1 + eq2) / 2;
        long long missingNum = eq2 - repeatedNum;

        return {(int)repeatedNum,(int)missingNum};
    }
};


// Using Xor
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {      

        int n = nums.size();
        int sumXor = 0;

        for (int i = 0; i < n; i++) {
            sumXor ^= nums[i];
            sumXor ^= (i + 1);
        }

        int pos = __builtin_ctzll(sumXor);

        int repeatedNum = 0, missingNum = 0;

        for (int i = 1; i <= n; i++) {
            if (i & (1 << pos)) {
                missingNum ^= i;
            } else {
                repeatedNum ^= i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] & (1 << pos)) {
                missingNum ^= nums[i];
            } else {
                repeatedNum ^= nums[i];
            } 
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == missingNum) cnt++;
        }
        if (cnt == 2) return {missingNum, repeatedNum};

        return {repeatedNum, missingNum}; 
    }
};