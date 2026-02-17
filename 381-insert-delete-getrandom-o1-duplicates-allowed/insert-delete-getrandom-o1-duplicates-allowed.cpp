class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notPresent = mp[val].empty();
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return notPresent;
    }

    bool remove(int val) {
        if (mp[val].empty())
            return false;

        int index = *mp[val].begin();
        mp[val].erase(index);

        int last = nums.back();

        if (index != nums.size() - 1) {
            nums[index] = last;

            mp[last].erase(nums.size() - 1);
            mp[last].insert(index);
        }

        nums.pop_back();
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};
