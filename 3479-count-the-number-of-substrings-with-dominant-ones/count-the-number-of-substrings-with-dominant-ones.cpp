class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> prefix(n);
        prefix[0] = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (s[i] == '1');
        }
        int totalSubs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int oneCount = prefix[j];
                if (i > 0) {
                    oneCount -= prefix[i - 1];
                }
                int zeroCount = j - i + 1 - oneCount;
                if ((zeroCount * zeroCount) > oneCount) {
                    int skipIndices = (zeroCount * zeroCount) - oneCount;
                    j += skipIndices - 1;
                } else if ((zeroCount * zeroCount) == oneCount) {
                    totalSubs += 1;
                } else {
                    totalSubs += 1;
                    // increase j till valid
                    int k = sqrt(oneCount) - zeroCount;
                    int next = j + k;
                    if (next >= n) {
                        //[j+1....n-1]
                        totalSubs += (n - j - 1);
                        break;
                    } else {
                        totalSubs += k;
                    }
                    j = next;
                }
            }
        }
        return totalSubs;
    }
};