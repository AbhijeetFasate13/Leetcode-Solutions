class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0)
            return "0";

        string ans;

        if ((num < 0) ^ (den < 0))
            ans += "-";


        long long n = llabs((long long)num);
        long long d = llabs((long long)den);

        ans += to_string(n / d);

        long long rem = n % d;

        if (rem == 0)
            return ans;

        ans += ".";

        unordered_map<long long, int> mp;

        while (rem != 0) {
            if (mp.count(rem)) {
                int pos = mp[rem];
                ans.insert(pos, "(");
                ans += ")";
                break;
            }
            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};
