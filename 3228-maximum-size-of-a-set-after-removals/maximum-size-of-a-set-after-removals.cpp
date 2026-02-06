class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        int n = nums1.size();
        int delete1 = n / 2, delete2 = n / 2;
        for (const auto& i : nums1) {
            if (mp1.find(i) == mp1.end())
                mp1[i]++;
            else if (delete1)
                delete1--;
        }

        for (const auto& i : nums2) {
            if (mp2.find(i) == mp2.end())
                mp2[i]++;
            else if (delete2)
                delete2--;
        }
        unordered_map<int, int> mp;
        for (const auto& i : mp1)
            mp[i.first] = i.second;
        for (const auto& i : mp2)
            mp[i.first] += i.second;
        int duplicates = 0;
        for (const auto& i : mp) {
            duplicates += i.second - 1;
        }
        int deletes = delete1 + delete2 - duplicates;
        deletes = max(0, deletes);
        return mp.size() - deletes;
    }
};