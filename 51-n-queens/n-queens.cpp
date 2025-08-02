class Solution {
    vector<int>checker;
    bool check(int row, int col, const vector<string>&board){
        for(int pRow = 0;pRow<row;pRow++){
            int pCol = checker[pRow];
            if(col==pCol or abs(pCol-col)==abs(pRow-row)){
                return false;
            }
        }
        return true;
    }
    void rec(int row, int n, vector<string>&board, vector<vector<string>>&solutionSet){
        if(row==n){
            solutionSet.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(check(row,col,board)){
                checker[row] = col;
                board[row][col] = 'Q';
                rec(row+1,n,board,solutionSet);
                board[row][col] = '.';
                checker[row] = -1;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        checker.resize(n,-1);
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>solutionSet;
        rec(0,n,board,solutionSet);
        return solutionSet;
    }
};