class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto fn = [&](int mid){
            int sum = 0;
            for(auto &i : nums){
                sum += (i + mid - 1) / mid;
            }
            return sum <= threshold;  
        };

        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = l + (r - l) / 2;
            if(fn(mid)){
                r = mid; 
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
