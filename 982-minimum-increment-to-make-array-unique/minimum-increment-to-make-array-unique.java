class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);

        int need = 0, moves = 0;
        for (int i = 0; i < nums.length; i++) {
            moves += Math.max(need - nums[i], 0);
            need = Math.max(need, nums[i]) + 1;
        }
        return moves;
    }
}