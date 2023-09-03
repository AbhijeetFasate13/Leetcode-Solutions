class Solution {
public:
    bool judgeCircle(string moves) {
        int l=0,u=0;
        for(auto i:moves){
            if(i=='U')u++;
            else if(i=='L')l++;
            else if(i=='R')l--;
            else u--;
        }
        return u==0 and l==0;
    }
};