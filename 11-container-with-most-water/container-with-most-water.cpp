class Solution {
    int calcArea(const int& left, const int& right, const vector<int>& height) {
        return (right - left) * min(height[left], height[right]);
    }

public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        int left = 0, right = n - 1;
        int maxArea = calcArea(left, right, height);
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
            maxArea = max(maxArea, calcArea(left, right, height));
        }
        return maxArea;
    }
};