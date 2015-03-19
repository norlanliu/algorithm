/*
 * =====================================================================================
 *
 *       Filename:  46_permutations.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 12:32:28 PM
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
		void EnumPermute(vector<int>& num, unsigned int start, vector<vector<int> >& ans){
			if(start == num.size()-1){
				ans.push_back(num);
				return;
			}
			unsigned int j;
			EnumPermute(num, start+1, ans);
			for(j = start+1; j < num.size(); ++j){
				std::swap(num[start],num[j]);
				EnumPermute(num, start+1, ans);
				std::swap(num[start], num[j]);
			}
		}
		vector<vector<int> > permute(vector<int>& num){
			vector<vector<int> > ans;
			if(num.size() != 0)
				EnumPermute(num, 0, ans);
			return ans;
		}
};

int main()
{
	vector<int> num = {2,1,4,3};
	Solution sln;
	vector<vector<int> > ans = sln.permute(num);
	for(auto& it : ans){
		for(auto i : it)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
