class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> reachable(n, 0);
        reachable[0] = 1;
        int pre = 0;
        for (int i = 1; i < n; i++) {
            if (i - minJump >= 0)
                pre += reachable[i - minJump];
            if (i - maxJump - 1 >= 0)
                pre -= reachable[i - maxJump - 1];
            reachable[i] = (pre > 0 && s[i] == '0');
        }

        return reachable[n - 1];
    }
};