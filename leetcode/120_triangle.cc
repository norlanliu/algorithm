/*
 * =====================================================================================
 *
 *       Filename:  120_triangle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2015 08:32:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<algorithm>
#include<iostream>

#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.size() == 0)
			return 0;
		int i, j, size, ans;
		size = triangle.size();
		for(i = 1; i != size; ++i){
			triangle[i][0] += triangle[i-1][0];
			for(j = 1; j != triangle[i].size()-1; ++j){
				triangle[i][j] += std::min(triangle[i-1][j-1], triangle[i-1][j]);
			}
			triangle[i][j] += triangle[i-1][j-1];
		}
		ans = triangle[i-1][0];
		for(auto k : triangle[i-1]){
			if(k < ans)
				ans = k;
		}
		return ans;
    }
};

int main(){
	vector<vector<int> > triangle = {{1}, {3,4}, {6,5,6}, {4,1,8,1}};
	Solution sln;
	int ans = sln.minimumTotal(triangle);
	cout<<ans<<endl;
	return 0;
}
