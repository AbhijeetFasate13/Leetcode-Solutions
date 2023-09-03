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
        long long ans = 0;
        for(int i=0;i<temp.size();i++){
            ans = ans*2 + temp[i]-'0';
        }
        return ans;
    }
};