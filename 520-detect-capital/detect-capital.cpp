class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int count;
        if(word[0]>='A' and word[0]<='Z'){
            count = n-1;
            for(int i=1;i<n;i++){
                if(word[i]>='A' and word[i]<='Z'){
                    count--;
                }
            }
            if(count==0)return true;
            count = n-1;
            for(int i=1;i<n;i++){
                if(word[i]>='a' and word[i]<='z'){
                    count--;
                }
            }
            if(count==0)return true;
        }
        else{
            count = n-1;
            for(int i=1;i<n;i++){
                if(word[i]>='a' and word[i]<='z'){
                    count--;
                }
            }
            if(count==0)return true;
        }
        return false;
    }
};