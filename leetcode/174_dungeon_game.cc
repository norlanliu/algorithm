/*
 * =====================================================================================
 *
 *       Filename:  174_dungeon_game.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2015 04:31:37 PM
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
#include <limits.h>
#include<vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
	void backtract(vector<vector<int>>& dungeon, int x, int y, long long sum, int hp, int& min){
		int x_size = dungeon.size() - 1;
		int y_size = dungeon[0].size() - 1;
		int hp_back = hp;
		long long tmp;
		bool end = true;
		if(y < y_size){
			end = false;
			sum += dungeon[x][y+1];
			tmp = 1-sum;
			if(tmp > hp){
				hp = tmp;
			}
			if(tmp < 0 || tmp < min){
				backtract(dungeon, x, y+1, sum, hp, min); 
			}
			sum -= dungeon[x][y+1];
		}
		if(x < x_size){
			end = false;
			sum += dungeon[x+1][y];
			tmp = 1-sum;
			if(tmp > hp_back){
				hp_back = tmp;
			}
			if(tmp < 0 || tmp < min){
				backtract(dungeon, x+1, y, sum, hp_back, min); 
			}
		}
		if(end){
			tmp = std::min(hp, hp_back);
			min = tmp < min ? tmp : min;
		}
	}
public:
    int calculateMinimumHP_bak(vector<vector<int>>& dungeon) {
		if(dungeon.size() == 0){
			return 1;
		}
        int ret = INT_MAX, hp = 1;
		if(dungeon[0][0] < 0){
			hp -= dungeon[0][0];
		}
		backtract(dungeon, 0, 0, dungeon[0][0], hp, ret);
		return ret;
    }
	/*
	 * x = dungeon[i][j], tmp = min(hp[i][j+1], hp[i+1][j]) - x
	 *			  |- tmp   (x < 0)
	 * hp[i][j] = |- 1     (x >= 0 && tmp <= 0)
	 *            |- tmp   (x >= 0 && tmp > 0)
	 * namely : hp[i][j] = max(1, tmp)
	 */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int row_size = dungeon.size();
		if(row_size == 0){
			return 1;
		}
		int column_size = dungeon[0].size();
		int hp[row_size][column_size];
		int i = row_size-1, j = column_size-1, m, n;
		int tmp;
		hp[i][j] = dungeon[i][j] > 0 ? 1 : 1 - dungeon[i][j];
		for(m = j - 1; m >= 0; m--){
			tmp = hp[i][m+1] - dungeon[i][m];
			hp[i][m] = max(1, tmp);
		}
		for(m = i - 1; m >= 0; m--){
			tmp = hp[m+1][j] - dungeon[m][j];
			hp[m][j] = max(1, tmp);
		}
		for(m = i - 1; m >= 0; m--){
			for(n = j - 1; n >= 0; n--){
				tmp = min(hp[m][n+1], hp[m+1][n]) - dungeon[m][n];
				hp[m][n] = max(1, tmp);
			}
		}
		return hp[0][0];
	}
};
int main(){
	Solution  sln;
	vector<vector<int>> dungeon = {
		{-2,-3,3},
		{-5,-10,1},
		{10,30,-5}
	};
	cout<<sln.calculateMinimumHP(dungeon)<<endl;
	return 0;
}
