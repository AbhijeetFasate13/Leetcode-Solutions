class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(row -> row[1]));
        int curr = intervals[0][1];
        int removals = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (curr > intervals[i][0]) {
                removals++;
            } else {
                curr = intervals[i][1];
            }
        }
        return removals;
    }
}