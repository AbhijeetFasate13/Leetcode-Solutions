class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> indices;
        vector<int> idxs(n);
        for (int i = 0; i < n; i++) {
            idxs[i] = indices[nums[i]].size();
            indices[nums[i]].push_back(i);
        }
        vector<int> result;
        for (int q : queries) {
            vector<int>& qind = indices[nums[q]];
            if (qind.size() == 1) {
                result.push_back(-1);
            } else {
                int j = idxs[q];
                int prev = qind[(j - 1 + qind.size()) % qind.size()];
                int nextt = qind[(j + 1) % qind.size()];
                int curr = qind[j];
                int dist1 = (nextt + n - curr) % n;
                int dist2 = (curr - prev + n) % n;

                result.push_back(min(dist1, dist2));
            }
        }

        return result;
    }
};