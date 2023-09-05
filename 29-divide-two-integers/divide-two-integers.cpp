class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1){
            return dividend;
        }
        if(divisor==-1){
            if(dividend!=INT_MIN)return 0-dividend;
            return INT_MAX;
        }
        long long count=0;
         if(dividend<0 and divisor<0){
             while(dividend<0){
                 dividend-=divisor;
                 count++;
             }
             if(dividend!=0)
             count--;
         }
         else if(dividend>0 and divisor<0){
             while(dividend>0){
                 dividend+=divisor;
                 count--;
             }
             if(dividend!=0)
             count++;
         }
         else if(dividend<0 and divisor>0){
             while(dividend<0){
                 dividend+=divisor;
                 count--;
             }
             if(dividend!=0)
             count++;
         }
         else{
             while(dividend>0){
                 dividend-=divisor;
                 count++;
             }
             if(dividend!=0)
             count--;
         }
         return count;
    }
};