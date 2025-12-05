class Solution {
    void countSort(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxEl + 1, 0);
        for (int x : nums)
            freq[x]++;
        int idx = 0;
        for (int i = 0; i <= maxEl; i++) {
            while (freq[i]--)
                nums[idx++] = i;
        }
    }

public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        countSort(temp);
        int mid = (n - 1) / 2;
        int end = n - 1;
        int ptr = 0;
        while (ptr < n && mid >= 0) {
            nums[ptr] = temp[mid--];
            ptr += 2;
        }

        ptr = 1;
        while (ptr < n && end > mid) {
            nums[ptr] = temp[end--];
            ptr += 2;
        }
    }
};
