/*
 * =====================================================================================
 *
 *       Filename:  78_subsets.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2015 10:09:16 PM
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
	int _n;
	void EnumAll(vector<int>& instance, vector<int>& data, int start, int k, vector<vector<int> >& ans){
		if(k == 0){
			ans.push_back(instance);
			return;
		}
		for(int i = start; i < _n - k; ++i){
			instance[k-1] = data[i];
			EnumAll(instance, data, i+1, k-1, ans);
		}
	}
	public:
		vector<vector<int> > subsets(vector<int> &S){
			vector<int> instance;
			vector<vector<int> > ans;
			_n = S.size() + 1;
			std::sort(S.begin(), S.end(), [](int a, int b){
					return a > b;
					});
			for(int i = 0; i < _n; ++i){
				instance.resize(i);
				EnumAll(instance, S, 0, i, ans);
			}
			return ans;
		}
};

int main(){
	Solution sln;
	vector<int> s = {1,2, 3};
	vector<vector<int> > ans = sln.subsets(s);
	for(auto & it : ans){
		for(auto i : it){
			cout<<i<<",";
		}
		cout<<endl;
	}
	return 0;
}
