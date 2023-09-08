#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool isValid(vector<vector<char>>&ans, int row, int col, char num) {
		for (int i = 0; i < 9; i++) {
			if (ans[i][col] == num)return false;
			if (ans[row][i] == num)return false;
			if (ans[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)return false;
		}
		return true;
	}
public:
	bool sudokuSolverhelper(vector<vector<char>>&ans) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (ans[i][j] != '.')continue;
				for (char k = '1'; k <= '9'; k++) {
					if (isValid(ans, i, j, k)) {
						ans[i][j] = k;
						if (sudokuSolverhelper(ans))return true;
						ans[i][j] = '.';
					}
				}
				return false;
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char>>&ans) {
		sudokuSolverhelper(ans);
	}

};
