/*
 * =====================================================================================
 *
 *       Filename:  130_surrounded_regions.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/01/2015 08:15:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string.h>
#include<vector>
#include<stack>
#include<iostream>
#include<utility>
using namespace std;



class Solution {
	const char CX = 'X';
	const char CO = 'O';
	int row;
	int column;
	void dfs(vector<vector<char> > &board, int i, int j, bool** mask){
		if(i != 0 && !mask[i-1][j] && board[i-1][j] == CO){
			mask[i-1][j] = true;
			dfs(board, i-1, j, mask);
		}
		if(j != column-1 && !mask[i][j+1] && board[i][j+1] == CO){
			mask[i][j+1] = true;
			dfs(board, i, j+1, mask);
		}
		if(i != row-1 && !mask[i+1][j] && board[i+1][j] == CO){
			mask[i+1][j] = true;
			dfs(board, i+1, j, mask);
		}
		if(j != 0 && !mask[i][j-1] && board[i][j-1] == CO){
			mask[i][j-1] = true;
			dfs(board, i, j-1, mask);
		}
	}
	void bfs(vector<vector<char> > &board, int i, int j, bool** mask){
		stack<pair<int, int> > s;
		s.push(make_pair(i, j));
		while(!s.empty()){
			i = s.top().first;
			j = s.top().second;
			s.pop();
			if(i != 0 && !mask[i-1][j] && board[i-1][j] == CO){
				mask[i-1][j] = true;
				s.push(make_pair(i-1, j));
			}
			if(j != column-1 && !mask[i][j+1] && board[i][j+1] == CO){
				mask[i][j+1] = true;
				s.push(make_pair(i, j+1));
			}
			if(i != row-1 && !mask[i+1][j] && board[i+1][j] == CO){
				mask[i+1][j] = true;
				s.push(make_pair(i+1, j));
			}
			if(j != 0 && !mask[i][j-1] && board[i][j-1] == CO){
				mask[i][j-1] = true;
				s.push(make_pair(i, j-1));
			}
		}
	}
public:
    void solve(vector<vector<char>> &board) {
		if(board.size() == 0)
			return;
		row = board.size();
		column = board[0].size();
		bool** mask;
		mask = new bool*[row];
		for(int i = 0; i != row; ++i){
			mask[i] = new bool[column];
			memset(mask[i], 0, column);
		}
		for(int j = 0; j != column; ++j){
			if(board[0][j] == CO && !mask[0][j]){
				mask[0][j] = true;
				bfs(board, 0, j, mask); 
			}
			if(board[row-1][j] == CO && !mask[row-1][j]){
				mask[row-1][j] = true;
				bfs(board, row-1, j, mask); 
			}
		}
		for(int i = 0; i != row; ++i){
			if(board[i][0] == CO && !mask[i][0]){
				mask[i][0] = true;
				bfs(board, i, 0, mask); 
			}
			if(board[i][column-1] == CO && !mask[i][column-1]){
				mask[i][column-1] = true;
				bfs(board, i, column-1, mask); 
			}
		}
		for(int i = 0; i != row; ++i){
			for(int j = 0; j != column; ++j){
				if(!mask[i][j])
					board[i][j] = CX;
			}
		}
		for(int i = 0; i != row; ++i){
			delete []mask[i];
		}
		delete[] mask;
    }
};

int main(){
	vector<vector<char> > board = {
		{'O','O','O','O'},
		{'X','O','X','X'},
		{'X','O','O','X'},
		{'X','X','X','X'}
	};

//	for(int i = 0; i < 250; ++i){
//		if(i & 1)
//			board.push_back(vector<char>(250, 'X'));
//		else
//			board.push_back(vector<char>(250, 'O'));
//	}
//	board[249][249] = 'O';

	Solution sln;
	sln.solve(board);

	for(auto& it : board){
		for(auto i : it){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
