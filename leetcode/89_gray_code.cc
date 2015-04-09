/*
 * =====================================================================================
 *
 *       Filename:  89_gray_code.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2015 11:23:40 AM
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

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans;
		ans.push_back(0);
		if(n == 0)
			return ans;
		int i = 1, j, tmp = 1;
		ans.push_back(1);
		for(i = 1; i != n; ++i){
			tmp <<= 1;
			for(j = ans.size()-1; j != -1; --j){
				ans.push_back(tmp | ans[j]);
			}
		}
		return ans;
	}
};

int main(){
	Solution sln;
	vector<int> ans = sln.grayCode(4);
	for(auto i : ans)
		cout<<i<<endl;
	return 0;
}
