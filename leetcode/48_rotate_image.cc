/*
 * =====================================================================================
 *
 *       Filename:  48_rotate_image.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 09:42:19 AM
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
#include<algorithm>
using namespace std;

class Solution{
	public:
		void rotate(vector<vector<int> > &matrix){
			int i, j, n, half_size;
			half_size = matrix.size() / 2;
			n = matrix.size() - 1;
			for(i = 0; i < half_size; ++i){
				for(j = i; j < n - i; ++j){
					std::swap(matrix[j][n-i], matrix[i][j]);
				}
				for(j = n-i; j > i; --j){
					std::swap(matrix[n-i][j], matrix[i][n-j]);
				}
				for(j = n-i; j > i; --j){
					std::swap(matrix[j][i], matrix[i][n-j]);
				}
			}
		}
};

int main(){
	vector<vector<int> > matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
	//	,10,11,12},
	//	{13,14,15,16}};
	Solution sln;
	sln.rotate(matrix);
	for(auto& it : matrix){
		for(auto i : it)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
