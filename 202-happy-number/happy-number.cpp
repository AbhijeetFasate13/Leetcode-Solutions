class Solution {
public:
    bool isHappy(int n) {
        set<int>already;
        already.insert(n);
        while(n!=1){
            int temp = n;
            int k=0;
            while(temp){
                k += (temp%10)*(temp%10);
                temp/=10;
            }
            if(already.count(k)){
                return false;
            }
            already.insert(k);
            n=k;
        }
        return true;
    }
};