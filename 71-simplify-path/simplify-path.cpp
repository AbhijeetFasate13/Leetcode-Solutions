class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "..") {
                    if (!stack.empty())
                        stack.pop_back();
                } else if (curr != "" and curr != ".") {
                    stack.push_back(curr);
                }
                curr.clear();
            } else {
                curr.push_back(path[i]);
            }
        }

        if (stack.empty())
            return "/";

        string ans;
        for (auto& dir : stack) {
            ans += "/" + dir;
        }
        return ans;
    }
};
