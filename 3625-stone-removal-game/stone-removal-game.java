class Solution {
    public boolean canAliceWin(int n) {
        boolean aliceWins = n >= 10;
        int removals = 10;
        while (n >= removals) {
            n -= removals;
            removals--;
            if (n >= removals)
                aliceWins = !aliceWins;
        }
        return aliceWins;
    }
}