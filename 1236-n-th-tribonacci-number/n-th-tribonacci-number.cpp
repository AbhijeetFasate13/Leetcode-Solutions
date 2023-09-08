class Solution {
public:
    int tribonacci(int n) {
        static vector<int>dp(38,-1);
        if(n==0)return dp[0]=0;
        if(n==1||n==2)return dp[n]=1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
    }
};