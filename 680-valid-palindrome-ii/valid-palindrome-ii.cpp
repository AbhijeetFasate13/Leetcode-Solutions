class Solution {
public:
    bool isPalindrome(int l,int r, string s){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int allowed=0;
        int low = 0, high=s.size()-1;
        while(high>low){
            if(allowed>1)return false;
            if(s[high]==s[low]){
                high--;
                low++;
            }
            else{
                if(isPalindrome(low,high-1,s)){
                    allowed++;
                    high-=2;
                    low++;
                }
                else if(isPalindrome(low+1,high,s)){
                    allowed++;
                    low+=2;
                    high--;
                }
                else{
                    return false;
                }
            }
        }
        if(allowed<=1)return true;
        return false;
    }
};