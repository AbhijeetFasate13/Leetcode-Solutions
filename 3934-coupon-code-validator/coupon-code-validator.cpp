class Solution {
    bool belongsTo(const char& given, const char& l, const char& r) {
        return given >= l and given <= r;
    }
    bool isAlphaNum(const string& s) {
        if (s.empty())
            return false;
        for (const char& c : s) {
            if (!belongsTo(c, 'a', 'z') and !belongsTo(c, 'A', 'Z') and
                !belongsTo(c, '0', '9') and c != '_') {
                return false;
            }
        }
        return true;
    }

    bool isAmong(const string& s) {
        unordered_map<string, int> checkAgainst;
        checkAgainst["electronics"];
        checkAgainst["grocery"];
        checkAgainst["pharmacy"];
        checkAgainst["restaurant"];
        return checkAgainst.find(s) != checkAgainst.end();
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<vector<string>> couponValidity;
        for (int i = 0; i < n; i++) {
            if (isAlphaNum(code[i]) and isAmong(businessLine[i]) and
                isActive[i]) {
                couponValidity.push_back({code[i], businessLine[i]});
            }
        }
        sort(begin(couponValidity), end(couponValidity),
             [&](const vector<string>& a, const vector<string>& b) {
                 if (a[1] == b[1])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });
        vector<string> ans;
        for (const auto& i : couponValidity) {
            ans.push_back(i[0]);
        }
        return ans;
    }
};