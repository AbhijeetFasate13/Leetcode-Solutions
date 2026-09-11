class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);

        for (const int& d : digits)
            freq[d]++;

        int ans = 0;

        for (int unit = 0; unit <= 8; unit += 2) {
            if (freq[unit] == 0)
                continue;

            freq[unit]--;

            for (int hundred = 1; hundred <= 9; hundred++) {
                if (freq[hundred] == 0)
                    continue;

                freq[hundred]--;

                for (int ten = 0; ten <= 9; ten++) {
                    if (freq[ten] > 0)
                        ans++;
                }

                freq[hundred]++;
            }

            freq[unit]++;
        }

        return ans;
    }
};