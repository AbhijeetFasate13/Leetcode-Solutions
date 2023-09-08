class Solution {
public:
    double poww(double x,int n){
        if(n==0)
        return 1*1.0;
        double res = poww(x,n/2);
        res*=res;
        if(n&1)
        res*=x;
        return res;
    }
    double myPow(double x, int n) {
        if(n==0||x==1)return 1.00000;
        if(x==-1)return n&1?-1.00000:1.00000;
        double num = 1;
        if(n>=0)
        num = poww(x,n);
        else{
            n = -1ll*n;
            num = poww(x,n);
            num = 1.0/num;
        }
        return num;
    }
};