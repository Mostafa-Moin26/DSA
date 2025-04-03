// Problem link ---->
https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence

class Solution {
  public:
  
    int binarySearch(vector<int> & a, int x, bool f) {
        int idx = -1;
        int low = 0, high = a.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (a[mid] < x) {
                low = mid + 1;
            } else if (a[mid] > x) {
                high = mid - 1;
            } else {
                idx = mid;
                if (f) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        return idx;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int left = binarySearch(arr, target, true);
        int right = binarySearch(arr, target, false);
        
        if (left == -1) {
            return 0;
        }
        
        return right - left + 1;
    }
};

// using stl lower_bound and upper_bound
class Solution {
  public:
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        int left = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        int right = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        
        if (left == arr.size() || arr[left] != target) {
            return 0;
        }
        
        return right - left;
    }
};