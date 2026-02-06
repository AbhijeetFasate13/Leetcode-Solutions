class Solution {
    void deleteDuplicates(const vector<int>& nums, unordered_map<int, int>& mp,
                          int& deletes) {
        for (const auto& i : nums) {
            if (mp.find(i) == mp.end())
                mp[i]++;
            else if (deletes)
                deletes--;
        }
    }

public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        int n = nums1.size();
        int delete1 = n / 2, delete2 = n / 2;
        deleteDuplicates(nums1, mp1, delete1);
        deleteDuplicates(nums2, mp2, delete2);
        int duplicates = 0, unique = 0;
        for (const auto& i : mp1) {
            if (mp2.find(i.first) == mp2.end()) {
                unique++;
                duplicates += i.second - 1;
            } else {
                unique++;
                duplicates += i.second + mp2[i.first] - 1;
            }
        }
        for (const auto& i : mp2)
            if (mp1.find(i.first) == mp1.end()) {
                unique++;
                duplicates += i.second - 1;
            }
        int deletes = delete1 + delete2 - duplicates;
        deletes = max(0, deletes);
        return unique - deletes;
    }
};