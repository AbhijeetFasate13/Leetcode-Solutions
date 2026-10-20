
class Solution {

    bool checkIfCyclicRotations(const vector<int>& a, const vector<int>& b,
                                const int& start, const int& end) {
        int len = end - start;

        vector<int> lps(len, 0);
        for (int i = 1, j = 0; i < len;) {
            if (b[start + i] == b[start + j]) {
                lps[i++] = ++j;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }

        for (int i = 0, j = 0; i < 2 * len - 1;) {
            int curr = a[start + (i % len)];

            if (curr == b[start + j]) {
                i++;
                j++;

                if (j == len)
                    return true;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    vector<int> getDivisors(const int& n) {
        vector<int> divisors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                divisors.push_back(i);
        }
        return divisors;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        int ans = 0;
        vector<int> divisors = getDivisors(n);
        for (const int& k : divisors) {
            bool ok = true;
            for (int i = 0; i < n && ok; i += k) {
                if (!checkIfCyclicRotations(nums, sorted_nums, i, i + k)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += k;
            }
        }

        return ans;
    }
};
