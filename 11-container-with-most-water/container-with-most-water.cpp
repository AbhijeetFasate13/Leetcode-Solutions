class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = -1;
        while (l < r) {
            int minHeight = min(height[l], height[r]);
            maxWater = max(maxWater, (r - l) * minHeight);
            height[l] < height[r] ? l++ : r--;
        }
        return maxWater;
    }
};