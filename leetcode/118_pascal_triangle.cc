/*
 * =====================================================================================
 *
 *       Filename:  118_pascal_triangle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2015 11:41:47 PM
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
		vector<vector<int> > generate(int numRows){
			vector<vector<int> > ans(numRows, vector<int>());
			int i, j;
			for(i = 0; i != numRows; ++i){
				ans[i].resize(i+1, 1);
				for(j = 1; j < i; ++j)
					ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
			}
			return ans;
		}
};
int main(){
	Solution sln;
	vector<vector<int> > ans = sln.generate(1);
	for(auto& it : ans){
		for(auto i : it)
			cout<<i<<",";
		cout<<endl;
	}
	return 0;
}
