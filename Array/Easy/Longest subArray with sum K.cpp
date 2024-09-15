// Problem Link ----->
https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k


// Solutions ----->

// brute force but it will get TLE for O(n^2)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        long long sum;
        int maxLen = 0;
        
        
        for (int i = 0; i < N; i++) {
            sum = 0;
            
            for (int j = i; j < N; j++) {
                
                sum += A[j];
                
                if (sum == K) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        return maxLen;
    }

};

// better solution using prefix sum hashing
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        
        map<long long, int> preSumMap;
        long long sum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < N; i++) {
            
            sum += A[i];
            
            if (sum == K) {
                maxLen = max(maxLen, i + 1);
            }
            
            long long remSum = sum - K;
            
            if (preSumMap.find(remSum) != preSumMap.end()) {
                int len = i - preSumMap[remSum];
                maxLen = max(maxLen, len);
            }
            
            if (preSumMap.find(sum) == preSumMap.end()) {
                preSumMap[sum] = i;
            }
        }
        
        return maxLen;
    }

};