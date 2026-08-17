class Solution {
    int calcCost(string& s) {
        int l = 0, r = s.size() - 1;
        int cost = 0;
        while (l < r) {
            char a = s[l], b = s[r];
            if (a == b) {
                l++;
                r--;
                continue;
            }
            if (a < b)
                swap(a, b);
            int currCost = a - b;
            cost += min(currCost, 26 - currCost);
            l++;
            r--;
        }
        return cost;
    }
    void leftRotate(string& s) {
        char c = s[0];
        s = s.substr(1);
        s = s + c;
    }

public:
    int minOperations(string s) {
        int n = s.size();
        int ans = calcCost(s);
        for (int i = 0; i < n; i++) {
            ans = min(ans, calcCost(s) + i);
            leftRotate(s);
        }
        return ans;
    }
};