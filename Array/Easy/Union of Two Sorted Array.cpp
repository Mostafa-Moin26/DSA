// Problem link ---->
https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays

// Solutions ----->
// brute force using set
// TC ----> O(nlogn + mlongn) + O(n + m)
// SC ----> O(n + m) + O(n + m)--->this space for only returning the ans, not for my algorithm
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        set<int> st;
        
        for (int i = 0; i < n; ++i) st.insert(arr1[i]); 
        for (int i = 0; i < m; ++i) st.insert(arr2[i]);
        
        vector<int> ans;
        
        for (auto i : st) ans.push_back(i);
        
        return ans;
    }
};

// Optimal solution using two pointer approach inspired from merge sort algorithm in the merge part
// TC ----> O(n + m)
// SC ----> O(n + m) this space for only returning the ans, not for my algorithm

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j]) {
                if (ans.empty() || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++;
            } else {
                if (ans.empty() || ans.back() != arr2[j]) {
                    ans.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        while (i < n) {
            if (ans.back() != arr1[i]) ans.push_back(arr1[i]);
            i++;
        }
        while (j < m) {
            if (ans.back() != arr2[j]) ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
};