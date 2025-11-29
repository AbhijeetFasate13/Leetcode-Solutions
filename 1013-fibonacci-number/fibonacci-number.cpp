class Solution {
    int dp[31];
public:
Solution(){
    memset(dp,-1,sizeof(dp));
}
    int fib(int n) {
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = fib(n-1)+fib(n-2);
    }
};