/*
 * =====================================================================================
 *
 *       Filename:  combination_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/18/2015 11:18:34 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution{
	public:

		bool findSum(vector<int>& candidates, int start, int end, int target, vector<vector<int> >& ans){
			static vector<int> data;
			int i;
			if(target == 0){
				ans.push_back(data);
				return false;
			}else if(target < 0){
				return false;
			}
			data.push_back(0);
			for( i = start; i < end; ++i){
				data[data.size()-1] = candidates[i];
				if(!findSum(candidates, i, end, target - candidates[i], ans)){
					break;
				}
			}
			data.pop_back();
			return true;
		}
		vector<vector<int> > combinationSum(vector<int> &candidates, int target){
			int end;
			vector<vector<int> > ans;
			std::sort(candidates.begin(), candidates.end());
			end = (std::upper_bound(candidates.begin(), candidates.end(), target) - candidates.begin());
			findSum(candidates, 0, end, target, ans);
			return ans;
		}
};

int main(){
	Solution sln;
	vector<int> candidates = {1, 2, 3, 4};
	int target = 8;
	vector<vector<int> > ans = sln.combinationSum(candidates, target);
	for(auto& it : ans){
		for(auto data : it){
			cout<<data<<" ";
		}
		cout<<endl;
	}
	return 0;
}
