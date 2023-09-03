class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)return n;
        long long base=1;
        long long count=0;
        while(base<=n){
            long long q = n/(base*10);
            long long r = n%(base*10);
            count += q*base + min(max(r-base+1,0ll),base);
            base*=10;
        }
        return count;
    }
};