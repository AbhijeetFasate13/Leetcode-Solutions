class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> randomSet;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) == mp.end()) {
            mp[val] = randomSet.size();
            randomSet.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        int idx = mp[val];
        int last = randomSet.back();
        randomSet[idx] = last;
        mp[last] = idx;
        mp.erase(val);
        randomSet.pop_back();
        return true;
    }

    int getRandom() {
        int n = randomSet.size();
        return randomSet[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */