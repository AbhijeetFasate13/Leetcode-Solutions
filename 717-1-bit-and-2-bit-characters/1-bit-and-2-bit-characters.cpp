class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int result=0;
        for(int i=0;i<n;i++){
            if(bits[i]==0){
                result=1;
            }
            else{
                result=2;
                i++;
            }
        }
        return result==1;
    }
};