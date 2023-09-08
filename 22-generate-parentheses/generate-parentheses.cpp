class Solution {
    vector<string>ans;
    void helper(int l,int r,int n,string container){
        if(l==n and r==n ){
            ans.push_back(container);
            return;
        }
        if(l<n){
            helper(l+1,r,n,container+'(');
        }
        if(r<n and r<l){
            helper(l,r+1,n,container+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return ans;
    }
};