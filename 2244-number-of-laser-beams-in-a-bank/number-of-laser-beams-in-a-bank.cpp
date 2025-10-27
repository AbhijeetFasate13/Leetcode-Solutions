class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = -1;
        int lasers = 0;
        vector<int> countArr(n);
        for (int i = 0; i < n; i++) {
            for (const char& c : bank[i]) {
                if (c == '1') {
                    countArr[i]++;
                }
            }
            if (!countArr[i])
                continue;
            if (prev == -1) {
                prev = countArr[i];
            } else {
                lasers += prev * countArr[i];
                prev = countArr[i];
            }
        }
        
        return lasers;
    }
};