class Solution {
    vector<int>primes;
public:
    Solution():primes(1e6+5,1){};
    void sieve(){
        primes[0]=primes[1]=0;
        for(int i=2;i*i<1e6+5;i++){
            if(primes[i]){
                for(int j=i*i;j<1e6+5;j+=i){
                    primes[j]=0;
                }
            }
        }
    }
    int countPrimeSetBits(int left, int right) {
        sieve();
        vector<int>dp(right+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=right;i++){
            dp[i]=dp[i/2]+i%2;
        }
        int count=0;
        for(int i=left;i<=right;i++){
            if(primes[dp[i]])count++;
        }
        return count;
    }
};