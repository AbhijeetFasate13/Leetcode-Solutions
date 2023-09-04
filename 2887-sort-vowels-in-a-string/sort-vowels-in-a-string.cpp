class Solution {
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<char>vowels;
        for(auto i:s){
            if(isVowel(i)){
                vowels.push_back(i);
            }
        }
        sort(begin(vowels),end(vowels));
        int ptr=0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=vowels[ptr];
                ptr++;
            }
        }
        return s;
    }
};