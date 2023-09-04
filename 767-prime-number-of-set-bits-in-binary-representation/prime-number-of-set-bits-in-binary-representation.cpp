class Solution {
public:
    bool isprime(int n){
        if(n==2||n==3||n==5||n==7||n==11||n==13||n==17||n==19)return true;
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int>dp(right+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=right;i++){
            dp[i]=dp[i/2]+i%2;
        }
        int count=0;
        for(int i=left;i<=right;i++){
            if(isprime(dp[i]))count++;
        }
        return count;
    }
};