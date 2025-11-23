class Solution {
    public String mergeAlternately(String word1, String word2) {
        int i = 0, a = 0, b = 0, m = word1.length(), n = word2.length();
        char[] mergedString = new char[m + n];
        while (a < m && b < n) {
            mergedString[i++] = word1.charAt(a++);
            mergedString[i++] = word2.charAt(b++);
        }
        while (a < m) {
            mergedString[i++] = word1.charAt(a++);
        }
        while (b < n) {
            mergedString[i++] = word2.charAt(b++);
        }
        return new String(mergedString);
    }
}