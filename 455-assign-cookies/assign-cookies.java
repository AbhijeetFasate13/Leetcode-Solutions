class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);

        int cookie = 0, greed = 0;

        int contentChildren = 0;
        while (greed < g.length && cookie < s.length) {
            while (cookie < s.length && g[greed] > s[cookie]) {
                cookie++;
            }
            if (cookie == s.length)
                break;
            greed++;
            cookie++;
            contentChildren++;
        }

        return contentChildren;
    }
}