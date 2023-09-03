class Solution {
public:
    int findComplement(int num) {
        string temp;
        while(num){
            if(num&1)temp.push_back('0');
            else temp.push_back('1');
            num>>=1;
        }
        reverse(begin(temp),end(temp));
        long long ans = stoll(temp,nullptr,2);
        return ans;
    }
};