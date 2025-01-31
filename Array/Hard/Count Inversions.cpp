// Problem link ------> 
https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

// Solutions ----->
// Brute force 
// near about O(n^2)

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        
        int ans = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) ans++;
            }
        }
        
        return ans;
    }
};


// Optimal 
// O(nlogn)

class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        
        vector<int> temp;
        int count = 0;
        
        for (int i = low; i <= high; i++) {
            if (left > mid) {
                temp.push_back(arr[right]);
                right++;
            } else if (right > high) {
                temp.push_back(arr[left]);
                left++;
            } else if (arr[left] > arr[right]) {
                count += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            } else {
                temp.push_back(arr[left]);
                left++;
            }
        }
        
        for (int i = 0; i < temp.size(); i++) {
            arr[low + i] = temp[i];
        }
        
        return count;
    }
    int mergeSort(vector<int> &arr, int low, int high) {
        
        if (low >= high) return 0;
        
        int mid = (low + high) / 2;
        
        int val1 = mergeSort(arr, low, mid);
        int val2 = mergeSort(arr, mid + 1, high);
        int val3 = merge(arr, low, mid, high);
        
        return val1 + val2 + val3;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        
       int ans =  mergeSort(arr, 0, arr.size() - 1);
        
        return ans;
    }
};



