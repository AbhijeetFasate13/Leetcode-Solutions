class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        for (const string& top : words)
            for (const string& bottom : words)
                for (const string& left : words)
                    for (const string& right : words) {
                        if (top == left or top == right or top == bottom or
                            bottom == left or bottom == right or left == right)
                            continue;
                        if (top[0] == left[0] and top[3] == right[0] and
                            bottom[0] == left[3] and bottom[3] == right[3])
                            ans.push_back({top, left, right, bottom});
                    }
        sort(begin(ans),end(ans));
        return ans;
    }
};