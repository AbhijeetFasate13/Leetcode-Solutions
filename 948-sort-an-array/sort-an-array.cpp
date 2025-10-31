class Solution {
    void rec(int i, vector<int>& nums) {
        if (i == nums.size() - 1) {
            return;
        }
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
        rec(i + 1, nums);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()>1e4){
            sort(begin(nums),end(nums));
            return nums;
        }
        rec(0, nums);
        return nums;
    }
};