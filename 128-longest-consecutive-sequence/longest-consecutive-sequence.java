class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        int lcs = 0;

        for (int num : set) {
            if (!set.contains(num - 1)) {
                int curr = num;
                while (set.contains(curr + 1)) {
                    curr++;
                }
                lcs = Math.max(lcs, curr - num + 1);
            }
        }

        return lcs;
    }
}