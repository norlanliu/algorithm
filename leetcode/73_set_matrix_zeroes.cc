/*
 * =====================================================================================
 *
 *       Filename:  73_set_matrix_zeroes.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2015 06:40:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>

#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		void setZeroes(vector<vector<int> > &matrix){
			if(matrix.size() == 0)
				return;
			int i, j, row, column;
			bool sign;
			bool mark[matrix.size()];
			row = matrix.size();
			column = matrix[0].size();
			memset(mark, 0, row); 
			for(j = 0; j < column; ++j){
				sign = false;
				for(i = 0; i < row; ++i){
					if(!matrix[i][j]){
						mark[i] = true;
						sign = true;
					}
				}
				if(sign){
					for(i = 0; i < row; ++i){
						matrix[i][j] = 0;
					}
				}
			}
			for(i = 0; i < row; ++i){
				if(mark[i])
					memset(matrix[i].data(), 0, sizeof(int) * column);
			}
		}
};

int main(){
	Solution sln;
	vector<vector<int> > matrix = {{0,1,2}, {1,2,3},{2,0,1}};
	for(auto& it : matrix){
		for(auto i : it)
			cout<<i<<",";
		cout<<endl;
	}
	sln.setZeroes(matrix);
	for(auto& it : matrix){
		for(auto i : it)
			cout<<i<<",";
		cout<<endl;
	}
	return 0;
}
