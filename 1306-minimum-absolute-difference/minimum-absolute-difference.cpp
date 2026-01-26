class Solution {
    int getMinDiff(vector<int>& a) {
        int n = a.size();
        sort(begin(a), end(a));
        int minDiff = a[1] - a[0];
        for (int i = 1; i < n - 1; i++) {
            minDiff = min(minDiff, a[i + 1] - a[i]);
        }
        return minDiff;
    }

public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = getMinDiff(arr);
        int n = arr.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};