class Solution {
public:
    char kthCharacter(int k) {
        int times = ceil(1.0 * log2(k));
        string word = "a";
        char add;
        int sz;
        while (times--) {
            sz = (int)word.size();
            for (int i = 0; i < sz; i++) {
                add = ((word[i] - 'a') + 1) % 26 + 'a';
                word.push_back(add);
            }
        }
        return word[k - 1];
    }
};