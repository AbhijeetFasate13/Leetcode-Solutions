class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {
        int n = (int)nums.size();
        prefix.resize(n + 1);
        prefix[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (auto& i : prefix)
            cout << i << " ";
        cout << endl;
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */