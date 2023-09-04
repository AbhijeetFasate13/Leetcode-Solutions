class Solution {
public:
    bool checkRecord(string s) {
        int a=0,l=0;
        int n=s.size();
        for(int i=0;i<n;+i++){
            if(s[i]=='A')a++;
            else if(s[i]=='L'){
                l=0;
                for(int j=i;j<min(i+3,n);j++){
                    if(s[j]=='L')l++;
                }
                if(l==3){
                    return false;
                }
            }
            if(a>1)return false;
        }
        return true;
    }
};