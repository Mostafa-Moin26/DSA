// Problem link ---->
https://leetcode.com/problems/count-good-numbers/description/

// Solution ---->
class Solution {
public:
    const int mod = 1e9 + 7;

    long long modPow(long long x, long long n, long long ans = 1) {
        if (n == 0) return ans;   
            
        if (n & 1) {
            return modPow(x, n - 1, (ans * x) % mod);
        }                   

        return modPow((x * x) % mod, n / 2, ans);
    }

    int countGoodNumbers(long long n) {
        long long evenPlaces = (n + 1) / 2; 
        long long oddPlaces  = n / 2;       

        long long ans = (modPow(5, evenPlaces) * modPow(4, oddPlaces)) % mod;

        return (int)ans;
    }
};

/* more tricky

Intuition
1. We know that every digit can have range 0 - 9.
2. In this range there are 5 even numbers and 4 prime numbers.
3. So, for every even position we have 5 options to fill it and for every odd position we have 4 options to fill it.

Approach
Let observe something for n = 5.
Options : 5 4 5 4 5
Position : 0 1 2 3 4
So, our answer will be (5 x 4) x (5 x 4) x 5
This can be seen as we have 20 options for every n/2 positions if we group positions in 2.
Since we are following 0-indexing ==> last position will be even for odd n and will have 5 options.

For even n we will have perfectly n/2 groups each having 20 options.

Thus we first find out 20^(n/2). If n is odd multiply it by 5. Then return.

For calculating power we will use recursive binary exponentiation.
*/

class Solution {
public:
    const int mod = 1e9 + 7;

    long long modPow(long long x, long long n, long long ans = 1) {
        if (n == 0) return ans;   
            
        if (n & 1) {
            return modPow(x, n - 1, (ans * x) % mod);
        }                   

        return modPow((x * x) % mod, n / 2, ans);
    }

    int countGoodNumbers(long long n) {

        long long ans = modPow(20, n / 2);

        return (n & 1) ? (ans * 5) % mod : ans;
    }
};