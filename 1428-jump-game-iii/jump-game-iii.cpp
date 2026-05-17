class Solution {
    vector<int> dp;
    bool helper(int start, const vector<int>& arr, vector<int>& visited) {
        if (start < 0 or start >= arr.size() or visited[start]) {
            return false;
        }
        if (arr[start] == 0) {
            return true;
        }
        if (dp[start] != -1)
            return dp[start];
        visited[start] = 1;
        return dp[start] = helper(start + arr[start], arr, visited) or
                           helper(start - arr[start], arr, visited);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        dp.resize(n, -1);
        vector<int> visited(n, 0);
        return helper(start, arr, visited);
    }
};