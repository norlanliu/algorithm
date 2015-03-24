/*
 * =====================================================================================
 *
 *       Filename:  54_spiral_matrix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2015 08:32:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix){
		int i, j, k, loop, row_size, column_size;
		vector<int> ans;
		row_size = matrix.size() - 1;
		if(row_size < 0)
			return ans;
		column_size = matrix[0].size() - 1;
		loop = (row_size < column_size ? row_size : column_size) / 2;
		for(k = 0; k <= loop; ++k){
			for(i = k, j = k;j < column_size - k; ++j)
				ans.push_back(matrix[i][j]);
			for(; i <= row_size - k; ++i)
				ans.push_back(matrix[i][j]);
			for(i -= 1, j -= 1; j >= k && i > k; --j)
				ans.push_back(matrix[i][j]);
			for(j += 1, i -= 1; i > k && j < column_size - k; --i)
				ans.push_back(matrix[i][j]);
		}
		return ans;
	}
};
int main(){
	vector<vector<int> > matrix = {{1,2,3},{4,5,6},{7,8,9}} ;
	Solution sln;
	vector<int> ans = sln.spiralOrder(matrix);
	for(auto it : ans){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
