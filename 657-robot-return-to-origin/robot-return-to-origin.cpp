class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0,r=0,u=0,d=0;
        for(auto i:moves){
            if(i=='U')u++;
            else if(i=='L')l++;
            else if(i=='R')r++;
            else d++;
        }
        return u==d and r==l;
    }
};