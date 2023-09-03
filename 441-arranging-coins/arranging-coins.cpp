class Solution {
public:
    int arrangeCoins(int n) {
        long long count =0;
        while(n*1ll>=(count*(count+1))/2){
            count++;
        }
        return count-1;
    }
};