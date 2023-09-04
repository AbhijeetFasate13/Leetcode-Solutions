class Solution {
public:
    bool isprime(int n){
        if(n==2||n==3||n==5||n==7||n==11||n==13||n==17||n==19)return true;
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int k = __builtin_popcount(i);
            if(isprime(k))count++;
        }
        return count;
    }
};