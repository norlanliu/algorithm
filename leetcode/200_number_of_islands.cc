/*
 * =====================================================================================
 *
 *       Filename:  200_number_of_islands.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2015 10:44:48 AM
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
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	void dfs(vector<vector<char>>& grid, int i, int j){
		if(grid[i][j] == '1'){
			grid[i][j] = '0';
			int row_size = grid.size() - 1;
			int column_size = grid[0].size() - 1;
			if(i != 0){
				dfs(grid, i - 1, j);
			}
			if(j != column_size){
				dfs(grid, i, j + 1);
			}
			if(i != row_size){
				dfs(grid, i + 1, j);
			}
			if(j != 0){
				dfs(grid, i, j - 1);
			}
		}
	}
public:
    int numIslands(vector<vector<char>>& grid) {
		if(grid.size() == 0){
			return 0;
		}
		int ret = 0, i, j, row_size = grid.size(), column_size = grid[0].size();
		for(i = 0; i < row_size; ++i){
			for(j = 0; j < column_size; ++j){
				if(grid[i][j] == '1'){
					dfs(grid, i, j);
					ret += 1;
				}
			}
		}
		return ret;
    }
};
int main(){
	vector<vector<char>> grid = {
		{'1'}
	};
	Solution sln;
	cout<<sln.numIslands(grid)<<endl;
	return 0;
}
