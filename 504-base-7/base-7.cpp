class Solution {
public:
    string convertToBase7(int num) {
        int ans=0,i=0;
        while(num){
            ans += (num%7)*pow(10,i);
            i++;
            num/=7;
        }
        return to_string(ans);
    }
};