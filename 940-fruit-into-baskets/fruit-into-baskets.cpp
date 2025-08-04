class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r;
        int maxLen = 1;
        unordered_map<int,int>mp;
        for(r = 0;r<fruits.size();r++){
            mp[fruits[r]]++;
            while(mp.size()>2){
                int key = fruits[l++];
                mp[key]--;
                if(mp[key]==0){
                    mp.erase(key);
                }
            }
            maxLen = max(r-l+1,maxLen);
        }
        return maxLen;
    }
};