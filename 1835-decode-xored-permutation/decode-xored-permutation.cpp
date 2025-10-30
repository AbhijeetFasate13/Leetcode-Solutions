class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x = 0;
        int n = encoded.size();
        for (int i = 1; i <= n + 1; i++) {
            x ^= i;
        }
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                x ^= encoded[i];
            }
        }
        vector<int> decoded = {x};
        for (const int& i : encoded) {
            decoded.push_back(decoded.back() ^ i);
        }
        return decoded;
    }
};