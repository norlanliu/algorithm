/*
 * =====================================================================================
 *
 *       Filename:  74_search_matrix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2015 08:48:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target){
			unsigned i;
			int j, count, step;
			if(matrix.size() == 0)
				return false;
			j = 0; count = matrix.size();
			while(count > 0){
				i = j;
				step = count / 2;
				i += step;
				if(matrix[i][0] < target){
					j = ++i;
					count -= (step + 1);
				}
				else
					count = step;
			}
			if(i != matrix.size() && matrix[i][0] == target)
				return true;
			else if(i > 0){
				vector<int>& row = matrix[i-1];
				j = 1; count = matrix[0].size()-1;
				while(count > 0){
					i = j;
					step = count / 2;
					i += step;
					if(row[i] < target){
						j = ++i;
						count -= (step + 1);
					}
					else
						count = step;
				}
				if(i != matrix[0].size() && row[i] == target)
					return true;
			}
			return false;
		}
};

int main(){
	Solution sln;
	vector<vector<int> > matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	bool ans = sln.searchMatrix(matrix, 11);
	cout<<ans<<endl;
	return 0;
}
