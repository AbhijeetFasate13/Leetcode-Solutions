class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto it = lower_bound(begin(letters), end(letters), target+1);
        if (it == end(letters)) {
            return letters.front();
        } else {
            return *it;
        }
    }
};
