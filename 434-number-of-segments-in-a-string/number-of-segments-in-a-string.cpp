class Solution {
public:
    int countSegments(string s) {
        istringstream mystream(s);
        string temp;
        int count=0;
        while(mystream>>temp){
            count++;
        }
        return count;
    }
};