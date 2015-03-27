/*
 * =====================================================================================
 *
 *       Filename:  64_min_path_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 11:06:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int i, j, m , n;
		m = grid.size();
		if(m > 0)
			n = grid[0].size();
		else
			return 0;
		int paths[m];
		//Initialize the paths
		paths[0] = grid[0][0];
		for(i = 1; i < m; ++i){
			paths[i] = grid[i][0] + paths[i-1];
		}
		//calculate the answer
		for(j = 1; j < n; ++j){
			paths[0] += grid[0][j];
			for(i = 1; i < m; ++i){
				paths[i] = (grid[i][j] + (paths[i] < paths[i-1] ? paths[i] : paths[i-1])); 
			}
		}
		return paths[m-1];
    }
};
