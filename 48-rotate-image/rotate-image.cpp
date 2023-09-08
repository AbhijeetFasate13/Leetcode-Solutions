class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //take transpose;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse rows
        for(int i=0;i<n;i++){
            reverse(begin(matrix[i]),end(matrix[i]));
        }
    }
};