class Solution {
    bool isprime(int n){
        if(n==1)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    } 
public:
    int primePalindrome(int n) {
        if(n>=8 and n<=11)return 11;
        for(int i=1;i<=30000;i++){
            string l = to_string(i);
            string r = l;
            reverse(begin(r),end(r));
            long long check = stoll(l+r.substr(1));
            if(check>=n and isprime(check)){
                return check;
            }
        }
        return -1;
    }
};