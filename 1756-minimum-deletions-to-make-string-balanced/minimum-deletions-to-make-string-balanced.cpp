class Solution {
public:
    int minimumDeletions(string s) {
        int aCount = 0, bCount = 0;
        for (const char& c : s) {
            if (c == 'b')
                bCount++;
            else
                aCount++;
        }
        int n = s.size();
        int leftSideB = 0, rightSideA = aCount;
        int ans = leftSideB + rightSideA;
        for (const char& c : s) {
            if (c == 'a') {
                rightSideA--;
            } else {
                leftSideB++;
            }
            ans = min(ans, leftSideB + rightSideA);
        }
        return ans;
    }
};