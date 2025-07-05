class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = (int)candyType.size();
        unordered_set<int> distinctTypes;
        for (const auto& i : candyType) {
            distinctTypes.insert(i);
        }
        return min(n / 2, (int)distinctTypes.size());
    }
};