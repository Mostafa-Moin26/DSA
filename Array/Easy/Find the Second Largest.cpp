// Problem Link ----->

// Solutions ----->

// brute force
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        if (arr[0] == arr[n - 1]) return -1;
        
        int i = n - 2;
        
        while (i >= 0 && arr[i] == arr[n - 1]) i--;
        
        return arr[i];
    }
};
// better
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        
        int firstLargest = -1;
        int secondLargest = -1;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > firstLargest) {
                firstLargest = arr[i];
            }
        }
        
        for (int i = 0; i < arr.size(); ++i) {
            
            if (arr[i] > secondLargest && arr[i] < firstLargest) {
                secondLargest = arr[i];
            }
        }
        
        return secondLargest;
    }
};

// optimal
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        
        int firstLargest = arr[0];
        int secondLargest = -1;
        
        for (int i = 1; i < arr.size(); ++i) {
            
            if (arr[i] > firstLargest) {
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            
            if (arr[i] > secondLargest && arr[i] < firstLargest) {
                    secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};