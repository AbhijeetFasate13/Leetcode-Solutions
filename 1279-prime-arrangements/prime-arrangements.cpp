class Solution {
    const int MOD = 1e9+7;
    vector<long long>fact;
public:
    Solution(){
        fact.resize(101);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<101;i++){
            fact[i]=((i%MOD)*(fact[i-1]%MOD))%MOD;
        }
    }
    int numPrimeArrangements(int n) {
        vector<int>prime(n+1,1);
        prime[0]=prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        long long count=0;
        for(int i=1;i<=n;i++){
            if(prime[i])count++;
        }
        return ((fact[count]%MOD)*(fact[n-count]%MOD))%MOD;
    }
};