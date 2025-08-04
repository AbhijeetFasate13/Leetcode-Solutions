class Solution {
    vector<vector<int>>dp;
public:
    Solution(){
        dp.resize(501,vector<int>(501,-1));
    }
    int calc(int i, int j, string word1, string word2){
        if(i==word1.size())return word2.length() - j; // insert all remaining from word2
        if(j==word2.size())return word1.length() - i; // delete all remaining from word1

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]!=word2[j]){
            int insertOp = calc(i,j+1,word1,word2); // inserting char at jth in word2
            int deleteOp = calc(i+1,j,word1,word2); // delete a char at ith in word1
            int replaceOp = calc(i+1,j+1,word1,word2); // move forward since both will match
            return dp[i][j] = 1+min({insertOp,deleteOp,replaceOp});
        }else{
            return dp[i][j] = calc(i+1,j+1,word1,word2); // a match so, move forward
        }
    }
    int minDistance(string word1, string word2) {
        return calc(0,0,word1,word2);
    }
};