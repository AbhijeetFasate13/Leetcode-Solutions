class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (const char& c : words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
            for (int j = 0; j < i; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    maxi = max(maxi, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return maxi;
    }
};