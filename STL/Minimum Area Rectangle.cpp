// Problem link ---->
https://leetcode.com/problems/minimum-area-rectangle/description/

// Solution --->
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int n = points.size();
        set<pair<int, int>> allPoints;

        for (int i = 0; i < n; i++) {
            allPoints.insert({points[i][0], points[i][1]});
        }

        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> p1 = {points[i][0], points[i][1]};
                pair<int, int> p2 = {points[j][0], points[j][1]};
                pair<int, int> p3 = {p2.first, p1.second};
                pair<int, int> p4 = {p1.first, p2.second};

                if (p1.first < p2.first && p1.second < p2.second && allPoints.count(p3) && allPoints.count(p4)) {
                    int area = (p2.first - p1.first) * (p2.second - p1.second);
                    res = min(res, area);
                }
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};