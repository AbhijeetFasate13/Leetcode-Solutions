class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>hash(26);
        for(auto i:magazine){
            hash[i-'a']++;
        }
        for(auto i:ransomNote){
            hash[i-'a']--;
            if(hash[i-'a']<0)return false;
        }
        return true;
    }
};