class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (capacity[i] >= itemSize) {
                if (minIdx == -1 || capacity[i] < capacity[minIdx]) {
                    minIdx = i;
                }
            }
        }
        return minIdx;
    }
};