class Solution {
public:
    bool isSquare(int c){
        if(c<0)return false;
        int k = sqrt(c);
        return k*k==c;
    }
    bool judgeSquareSum(int c) {
        if(c%4==3)return false;
        for(long long i=0;i*i<=c+1;i++){
            if(isSquare(c-i*i))return true;
        }
        return false;
    }
};