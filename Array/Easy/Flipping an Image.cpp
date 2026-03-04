// Problem link ---->
https://leetcode.com/problems/flipping-an-image/description/

// Solutions ---->

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();

        int l, r;

        for (int i = 0; i < cols; i++) {
            l = 0, r = cols - 1;

            while (l <= r) {
                swap(image[i][l], image[i][r]);
                image[i][l] = image[i][l] ? 0 : 1;

                if (l != r) {
                    image[i][r] = image[i][r] ? 0 : 1;
                }

                l++, r--;
            }
        }

        return image;
    }
};

// using xor (^)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        int cols = image[0].size();

        int l, r;

        for (int i = 0; i < cols; i++) {
            l = 0, r = cols - 1;

            while (l <= r) {
                swap(image[i][l], image[i][r]);
                image[i][l] ^= 1;

                if (l != r) {
                    image[i][r] ^= 1;
                }

                l++, r--;
            }
        }

        return image;
    }
};

// easy code using sort
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for (int i = 0; i < image.size(); i++) {

            reverse(image[i].begin(), image[i].end());

            for (int j = 0; j < image[0].size(); j++) {
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }
};