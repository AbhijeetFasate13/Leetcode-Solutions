class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)return 0;
        vector<long long>dp(n,1);
        dp[0]=dp[1]=0;
        for(long long i=2;i*i<n;i++){
            if(dp[i]){
                for(long long j=i*i;j<n;j+=i){
                    dp[j]=0;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i])count++;
        }
        return count;
    }
};
