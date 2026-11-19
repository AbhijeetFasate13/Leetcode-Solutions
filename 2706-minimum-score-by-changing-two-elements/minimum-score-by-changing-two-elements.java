class Solution {
    public int minimizeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        int ans = Math.min(nums[n - 1] - nums[2], nums[n - 3] - nums[0]);

        return Math.min(ans, nums[n - 2] - nums[1]);
    }
}