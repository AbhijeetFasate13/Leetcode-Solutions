class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> rems(3);
        for (const int& i : stones) {
            rems[i % 3]++;
        }
        if (rems[0] % 2 == 0) {
            return rems[1] > 0 and rems[2] > 0;
        }
        return abs(rems[1] - rems[2]) > 2;
    }
};