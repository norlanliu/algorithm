/*
 * =====================================================================================
 *
 *       Filename:  77_combinations.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2015 11:10:25 AM
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
	int _n;
	int _k;
	void EnumConbinations(vector<int>& instance, int start, int k, vector<vector<int> >& ans){
		if(k == 0){
			ans.push_back(instance);
			return;
		}
		for(int i = start; i < _n; ++i){
			instance[_k-k] = i;
			EnumConbinations(instance, i+1, k-1, ans);
		}
	}
	public:
		vector<vector<int> > combine(int n, int k){
			vector<int> instance(k, 0);
			vector<vector<int> > ans;
			_n = n+1; 
			_k = k;
			EnumConbinations(instance, 1, k, ans);
			return ans;
		}
};

int main(){
	Solution sln;
	vector<vector<int> > ans = sln.combine(4, 2);
	for(auto& it : ans){
		for(auto i : it){
			cout<<i<<",";
		}
		cout<<endl;
	}
	return 0;
}
