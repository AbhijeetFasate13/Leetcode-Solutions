class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int>hash1(26),hash2(26);
        for(auto i:jewels){
            if(i>='a' and i<='z')hash1[i-'a']++;
            else hash2[i-'A']++;
        }
        int count=0;
        for(auto i:stones){
            if(i>='a' and i<='z'){
            if(hash1[i-'a']>0)count++;
            }
            else{
                if(hash2[i-'A']>0)count++;
            }
        }
        return count;
    }
};