class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int>si(26),ti(26);
        for(auto i:s){
            si[i-'a']++;
        }
        for(auto i:t){
            ti[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(si[i]!=ti[i])return false;
        }
        return true;
    }
};