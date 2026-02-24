class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (const int& i : answers) {
            mp[i]++;
        }
        int rabbits = 0;
        for (const auto& i : mp) {
            if (i.second % (i.first + 1) != 0) {
                rabbits += i.first + 1;
            }
            rabbits += (i.second / (i.first + 1)) * (i.first + 1);
        }
        return rabbits;
    }
};