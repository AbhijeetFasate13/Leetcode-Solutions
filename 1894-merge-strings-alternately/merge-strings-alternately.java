class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder mergedString = new StringBuilder();
        int a = 0, b = 0, m = word1.length(), n = word2.length();
        while(a<m && b<n){
            mergedString.append(word1.charAt(a++));
            mergedString.append(word2.charAt(b++));
        }
        while(a<m){
            mergedString.append(word1.charAt(a++));
        }
        while(b<n){
            mergedString.append(word2.charAt(b++));
        }
        return mergedString.toString();
    }
}