class Solution {
public:
    char findTheDifference(string s, string t) {
        int k = 0;
        for(auto i:s){
            k^= (i-'a');
        }
        for(auto i:t){
            k^=(i-'a');
        }
        return char(k+'a');
    }
};