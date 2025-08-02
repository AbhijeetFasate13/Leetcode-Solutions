class Solution {
    vector<int>checker;
    bool check(int row, int col){
        for(int pRow=0;pRow<row;pRow++){
            int pCol = checker[pRow];
            if(pCol==col or abs(pCol-col)==abs(pRow-row)){
                return false;
            }
        }
        return true;
    }
    void rec(int row, int n, int& solCount){
        if(row==n){
            solCount++;
            return;
        }
        for(int col = 0;col<n;col++){
            if(check(row,col)){
                checker[row] = col;
                rec(row+1,n,solCount);
                checker[row] = -1;
            }
        }
    }
public:
    int totalNQueens(int n) {
        checker.resize(n,-1);
        int solCount = 0;
        rec(0,n,solCount);
        return solCount;
    }
};