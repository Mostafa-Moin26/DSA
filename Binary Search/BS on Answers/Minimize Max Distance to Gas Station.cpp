// Problem link ---->
https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1?

// Solution ---->

// Brute force
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        vector<int> howMany(n - 1, 0);
        
        for (int gasStations = 1; gasStations <= k; gasStations++) {
            
            long double maxSection = -1;
            int maxIndx = -1;
            
            for (int i = 0; i < n - 1; i++) {
                
                long double diff = stations[i + 1] - stations[i];
                long double sectionLength = diff / (long double)(howMany[i] + 1);
                
                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxIndx = i;
                }
            }
            howMany[maxIndx]++;
        }
        
        long double ans = -1;
        
        for (int i = 0; i < n - 1; i++) {
            
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (long double) (howMany[i] + 1);
            
            ans = max(ans, sectionLength);
        }
        
        return ans;
        
    }
};

// Better
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        vector<int> howMany(n - 1, 0);
        priority_queue<pair<long double, int>> pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({stations[i + 1] - stations[i], i});
        }

        for (int gasStations = 1; gasStations <= k; gasStations++) {
            auto top = pq.top(); pq.pop();
            int indx = top.second;
            howMany[indx]++;

            long double diff = stations[indx + 1] - stations[indx];
            long double sectionLen = (long double)diff / (howMany[indx] + 1);

            pq.push({sectionLen, indx});
        }

        return round(pq.top().first * 100.0) / 100.0;  
    }
};
