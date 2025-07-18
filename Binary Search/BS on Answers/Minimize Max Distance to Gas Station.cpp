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

// Optimal using Binary search
class Solution {
  public:
  
    int numberOfGasSationRequired(double dist, vector<int> &stations) {
        
        int cnt = 0;
        
        for (int i = 0; i < stations.size() - 1; i++) {
            
            int numberInBetween = (stations[i + 1] - stations[i]) / dist;
            
            if ((stations[i + 1] - stations[i]) == numberInBetween * dist) {
                numberInBetween--;
            }
            
            cnt += numberInBetween;
            
        }
        
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        
        int n = stations.size();
        
        double low = 0, high = 0;
        
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (double)(stations[i + 1] - stations[i]));
        }
        
        double diff = 0.000001;
        
        double ans = 0;
        
        while (high - low > diff) {
            
            double mid = (low + high) / 2.0;
            
            int cnt = numberOfGasSationRequired(mid, stations);
            
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
            
        }
        
        return high;
    }
};

// Another Optimal binary search approach
class Solution {
  public:
  
    bool check(long double dist, vector<int> &stations, int k) {
        
        int cnt = 0;
        
        for (int i = 0; i < stations.size() - 1; i++) {
            
            int diff = (stations[i + 1] - stations[i]);
            
            if (diff > dist) {
                cnt += diff / dist;
            }
        }
        
        if (cnt > k) {
            return false;
        }
        
        return true;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        
        int n = stations.size();
        
        double low = 0, high = stations[n - 1] - stations[0];
        
        double diff = 0.000001;
        
        double ans = 0;
        
        while (low <= high) {
            
            double mid = (low + high) / 2;
            
            if (check(mid, stations, k)) {
                ans = mid;
                high = mid - diff;
            } else {
                low = mid + diff;
            }
            
        }
        
        return ans;
    }
};