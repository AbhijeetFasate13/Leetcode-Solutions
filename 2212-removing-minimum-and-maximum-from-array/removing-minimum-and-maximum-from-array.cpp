class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int a = min_element(nums.begin(), nums.end()) - nums.begin() + 1;
        int b = max_element(nums.begin(), nums.end()) - nums.begin() + 1;

        if (a > b)
            swap(a, b);
        return min({b, n - a + 1, a + n - b + 1});
    }
};