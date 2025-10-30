class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x = 0;
        int n = encoded.size();
        for (int i = 1; i <= n + 1; i++) {
            if (i & 1 and i < n) {
                x ^= encoded[i];
            }
            x ^= i;
        }
        vector<int> decoded = {x};
        for (const int& i : encoded) {
            decoded.push_back(decoded.back() ^ i);
        }
        return decoded;
    }
};