class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0, high = (num*1ll+1);
        while(high-low>1){
            long long mid = low+(high-low)/2;
            if(mid*mid<=num){
                low=mid;
            }
            else{
                high = mid;
            }
        }
        if(low*low==num)return true;
        return false;
    }
};