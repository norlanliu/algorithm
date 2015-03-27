/*
 * =====================================================================================
 *
 *       Filename:  63_unique_path2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 10:06:44 AM
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
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int i, j, m , n;
		m = obstacleGrid.size();
		if(m > 0)
			n = obstacleGrid[0].size();
		else
			return 0;
		int row_paths[m];
		//Initialize the row_paths
		row_paths[0] = obstacleGrid[0][0] ? 0 : 1;
		for(i = 1; i < m; ++i){
			row_paths[i] = obstacleGrid[i-1][0] ? 0 : row_paths[i-1];
		}
		//calculate the answer
		for(j = 1; j < n; ++j){
			for(i = 1; i < m; ++i){
				if(obstacleGrid[i][j-1])
					row_paths[i] = 0;
				if(!obstacleGrid[i-1][j])
					row_paths[i] += row_paths[i-1]; 
			}
			row_paths[0] = obstacleGrid[0][j] ? 0 : row_paths[0];
		}
		if(obstacleGrid[m-1][n-1])
			return 0;
		return row_paths[m-1];
    }
};
