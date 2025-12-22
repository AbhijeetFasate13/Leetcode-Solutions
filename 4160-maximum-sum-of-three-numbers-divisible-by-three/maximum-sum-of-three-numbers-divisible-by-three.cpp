class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> groupsBasedOnRem(3);
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int first0 = -1, first1 = -1, first2 = -1;
        for (const int& num : nums) {
            groupsBasedOnRem[num % 3].push_back(num);
            if (num % 3 == 0 and first0 == -1) {
                first0 = num;
            }
            if (num % 3 == 1 and first1 == -1) {
                first1 = num;
            }
            if (num % 3 == 2 and first2 == -1) {
                first2 = num;
            }
        }
        int maxx = (first0 == -1 or first1 == -1 or first2 == -1)
                       ? 0
                       : first1 + first2 + first0;
        for (int i = 0; i < 3; i++) {
            int sz = groupsBasedOnRem[i].size();
            if (sz < 3)
                continue;
            int sum = 0;
            for (int j = 0; j < 3; j++) {
                sum += groupsBasedOnRem[i][j];
            }
            maxx = max(maxx, sum);
        }
        return maxx;
    }
};