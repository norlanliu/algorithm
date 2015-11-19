/*
 * =====================================================================================
 *
 *       Filename:  37_soduku.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/19/2015 03:41:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include <string.h>
#include <memory.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
	void findNextPos(vector<vector<char>> &board, int& i, int& j){
		int tmpj = j;
		for(; i < 9; ++i){
			for(; tmpj < 9; ++tmpj){
				if(board[i][tmpj] == '.'){
					j = tmpj;
					return;
				}
			}
			tmpj = 0;
		}
		j = 9;
	}
	bool backtracking(vector<vector<char>> &board, int i, int j, bool (*row)[10], bool (*column)[10], bool (*square)[10]) {
		if(i == 9 && j == 9){
			return true;
		}
		int t, ni, nj;
		ni = i, nj = j+1;
		findNextPos(board, ni, nj);
		if(i < 3){
			t = j/3;
		} else {
			t = pow(2, i/3) + i/3 + j/3;
		}
		for(int k = 1; k < 10; k++) {

			if(!row[i][k] && !column[j][k] && !square[t][k]){
				board[i][j] = k + '0';
				row[i][k] = true;
				column[j][k] = true;
				square[t][k] = true;
				if(backtracking(board, ni, nj, row, column, square)){
					return true;
				}else{
					board[i][j] = '.';
					row[i][k] = false;
					column[j][k] = false;
					square[t][k] = false;
				}
			}
		}
		return false;
	}
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool row[9][10], column[9][10], square[9][10];
		memset(row, 0, 90 * sizeof(bool));
		memset(column, 0, 90 * sizeof(bool));
		memset(square, 0, 90 * sizeof(bool));

		int i, j, k, t;
		for(i = 0; i < 9; ++i){
			for(j = 0; j < 9; ++j){
				k = board[i][j];
				if(k != '.'){
					k -= '0';
					row[i][k] = true;
					column[j][k] = true;
					if(i < 3){
						t = j/3;
					} else {
						t = pow(2, i/3) + i/3 + j/3;
					}
					square[t][k] = true;
				}
			}
		}
		i = 0, j = 0;
		findNextPos(board, i, j);
		backtracking(board, i, j, row, column, square);
    }
};

int main() {
	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	Solution sln;
	sln.solveSudoku(board);
	for(auto& b : board){
		for(auto i : b){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
