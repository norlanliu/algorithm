/*
 * =====================================================================================
 *
 *       Filename:  79_word_search.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2015 10:04:07 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution{
	int _row_size;
	int _column_size;
	bool backtracking(vector<vector<char> > &board, string& word, bool* mark, int i, int j, int k){
		if(k == word.size()-1)
			return true;
		mark[i*_column_size + j] = true;
		if(i != 0 && !mark[(i-1)*_column_size + j]
				&& board[i-1][j] == word[k+1]){
			if(backtracking(board, word, mark, i-1, j, k+1))
				return true;
		}
		if(j != _column_size-1 && !mark[i*_column_size + j + 1]
				&& board[i][j+1] == word[k+1]){
			if(backtracking(board, word, mark, i, j+1, k+1))
				return true;
		}
		if(i != _row_size - 1 && !mark[(i+1)*_column_size + j]
				&& board[i+1][j] == word[k+1]){
			if(backtracking(board, word, mark, i+1, j, k+1))
				return true;
		}
		if(j != 0 && !mark[i*_column_size + j - 1]
				&& board[i][j-1] == word[k+1]){
			if(backtracking(board, word, mark, i, j-1, k+1))
				return true;
		}
		mark[i*_column_size + j] = false;
		return false;

	}
public:
	bool exist(vector<vector<char> > &board, string word){
		int i, j;
		bool *mark;
		_row_size = board.size();
		if(_row_size == 0)
			return false;
		_column_size = board[0].size();
		mark = (bool*)malloc(_row_size * _column_size);

		for(i = 0; i < _row_size; ++i){
			for(j = 0; j < _column_size; ++j){
				if(board[i][j] == word[0]){
					memset(mark, 0, _row_size * _column_size);
					if(backtracking(board, word, mark, i, j, 0)){
						free(mark);
						return true;
					}
				}
			}
		}
		free(mark);
		return false;
	}
public:
	struct Index{
		int row;
		int column;
		Index(int r, int c):row(r), column(c){}
	};
		bool exist_old(vector<vector<char> > &board, string word){
			int i, j, row_size, column_size;
			unsigned k;
			stack<Index> space;
			bool *mark, signal;
			Index next(0, 0);
			row_size = board.size();
			if(row_size == 0)
				return false;
			column_size = board[0].size();
			mark = (bool*)malloc(row_size*column_size);

			for(i = 0; i < row_size; ++i){
				for(j = 0; j < column_size; ++j){
					if(board[i][j] == word[0]){
						memset(mark, 0, row_size*column_size);
						k = 0;
						space.push(Index(i, j));
						while(space.size() != 0){
							if(k == word.size()-1){
								free(mark);
								return true;
							}
							signal = false;
							next = space.top();
							space.pop();
							mark[next.row * column_size + next.column] = true;
							if(next.row != 0 && !mark[(next.row-1)*column_size + next.column]
									&& board[next.row-1][next.column] == word[k+1]){
								space.push(Index(next.row-1, next.column));
								signal = true;
							}
							if(next.column != column_size-1 && !mark[next.row*column_size + next.column + 1]
									&& board[next.row][next.column+1] == word[k+1]){
								space.push(Index(next.row, next.column+1));
								signal = true;
							}
							if(next.row != row_size-1 && !mark[(next.row+1)*column_size + next.column]
									&& board[next.row+1][next.column] == word[k+1]){
								space.push(Index(next.row+1, next.column));
								signal = true;
							}
							if(next.column != 0 && !mark[next.row*column_size + next.column - 1]
									&& board[next.row][next.column-1] == word[k+1]){
								space.push(Index(next.row, next.column-1));
								signal = true;
							}
							if(signal){
								mark[next.row * column_size + next.column] = false;
								k += 1;
							}
						}
					}
				}
			}
			free(mark);
			return false;
		}
};

int main(){
	vector<vector<char> > board = {
		{'a', 'a'}};
	Solution sln;
	bool ans = sln.exist(board, "aaa");
	cout<<ans<<endl;
	return 0;
}
