class Solution {
    unordered_map<string, int> powOfTwo;

public:
    Solution() {
        int x = 1;
        while (true) {
            string temp = to_string(x);
            sort(temp.begin(), temp.end());
            powOfTwo[temp]++;
            x *= 2;
            if (x >= INT_MAX / 2)
                break;
        }
    }
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        return powOfTwo.count(num);
    }
};