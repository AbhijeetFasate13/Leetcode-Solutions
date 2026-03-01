class Solution {
public:
    int minPartitions(string n) {
        int maxm = 1;
        while (!n.empty()) {
            maxm = max(maxm, n.back() - '0');
            n.pop_back();
            if (maxm == 9)
                break;
        }
        return maxm;
    }
};