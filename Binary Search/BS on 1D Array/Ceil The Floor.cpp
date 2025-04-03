// Problem link --->
http://geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor
// Solution --->
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        
        int f = -1, c = INT_MAX;
        
        for (int i = 0; i < arr.size(); i++) {
            
            if (arr[i] <= x) {
                f = max(f, arr[i]);
            }
            if (arr[i] >= x) {
                c = min(c, arr[i]);
            }
        }
        
        return {f, c == INT_MAX ? -1 : c};
    }

// Using Binary Search
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here   
        int f = -1, c = -1;
        sort(arr.begin(), arr.end());
        
        // finding floor value of x
        int low = 0, high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] <= x) {
                f = arr[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // Finding ceil value of x 
        low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] >= x) {
                c = arr[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return {f, c};   

    }