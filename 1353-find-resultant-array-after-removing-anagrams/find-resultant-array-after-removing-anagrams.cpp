class Solution {
    void sortAndSave(string& prev, const string word) {
        prev = word;
        sort(begin(prev), end(prev));
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> telescope;
        int n = words.size();
        telescope.push(words[0]);
        string prev, curr;
        sortAndSave(prev, telescope.top());

        for (int i = 1; i < n; i++) {
            curr = words[i];
            sort(curr.begin(), curr.end());
            if (prev != curr) {
                telescope.push(words[i]);
                sortAndSave(prev, words[i]);
            }
        }
        vector<string> result;
        while (!telescope.empty()) {
            result.push_back(telescope.top());
            telescope.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};