class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n);
        set<pair<long long, int>> adjSums;
        vector<int> nextIndex(n);
        vector<int> prevIndex(n);
        int badPairs = 0;
        for (int i = 0; i < n; i++) {
            temp[i] = nums[i];
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
            if (i != n - 1) {
                adjSums.insert({nums[i] + nums[i + 1], i});
                if (nums[i] > nums[i + 1])
                    badPairs++;
            }
        }

        int moves = 0;

        while (badPairs > 0) {
            int first = adjSums.begin()->second;
            adjSums.erase(begin(adjSums));
            int second = nextIndex[first];
            int firstLeft = prevIndex[first];
            int secondRight = nextIndex[second];
            if (temp[first] > temp[second]) {
                badPairs--;
            }
            if (firstLeft >= 0) {
                if (temp[firstLeft] > temp[first] &&
                    temp[firstLeft] <= temp[first] + temp[second]) {
                    badPairs--;
                } else if (temp[firstLeft] <= temp[first] &&
                           temp[firstLeft] > temp[first] + temp[second]) {
                    badPairs++;
                }
            }
            if (secondRight < n) {
                if (temp[secondRight] >= temp[second] &&
                    temp[secondRight] < temp[first] + temp[second]) {
                    badPairs++;
                } else if (temp[secondRight] < temp[second] &&
                           temp[secondRight] >= temp[first] + temp[second]) {
                    badPairs--;
                }
            }
            if (firstLeft >= 0) {
                adjSums.erase({temp[firstLeft] + temp[first], firstLeft});
                adjSums.insert(
                    {temp[firstLeft] + temp[first] + temp[second], firstLeft});
            }
            if (secondRight < n) {
                adjSums.erase({temp[second] + temp[secondRight], second});
                adjSums.insert(
                    {temp[first] + temp[second] + temp[secondRight], first});
                prevIndex[secondRight] = first;
            }
            nextIndex[first] = secondRight;
            temp[first] += temp[second];
            moves++;
        }

        return moves;
    }
};