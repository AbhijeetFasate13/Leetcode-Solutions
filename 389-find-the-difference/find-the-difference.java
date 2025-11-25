class Solution {
    public char findTheDifference(String s, String t) {
        int[] alphabets = new int[26];
        for (char c : s.toCharArray()) {
            alphabets[c - 'a']++;
        }
        for (char c : t.toCharArray()) {
            alphabets[c - 'a']--;
        }
        char c = 'a';
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] == -1) {
                c = (char) (i + 'a');
            }
        }
        return c;
    }
}