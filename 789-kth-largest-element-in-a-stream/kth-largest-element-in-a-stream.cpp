class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> ans;
    int maxSize;

public:
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        for (int i = 0; i < nums.size(); i++) {
            ans.push(nums[i]);
            if (ans.size() > maxSize) {
                ans.pop();
            }
        }
    }

    int add(int val) {
        ans.push(val);
        while (ans.size() > maxSize) {
            ans.pop();
        }
        return ans.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */