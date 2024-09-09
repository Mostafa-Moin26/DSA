// Nice algorithm but it will get TLE
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    
    void recursiveBubble(int arr[], int i, int j) {
        
        if (i == 0) return;
        
        if (i > j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            
            recursiveBubble(arr, i, j + 1);
        } 
        
        recursiveBubble(arr, i - 1, 0);
    } 
    void bubbleSort(int arr[], int n) {
        // Your code here
        
        recursiveBubble(arr, n - 1, 0);
    }
};

// Optimal recursive solution
class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        if (n == 1) return;
        int didSwap = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        
        if (didSwap == 0) return;
        
        bubbleSort(arr, n - 1);
    }
};