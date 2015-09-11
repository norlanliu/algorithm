/*
 * =====================================================================================
 *
 *       Filename:  216_combination_sum3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/11/2015 05:21:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
	bool backtrack(vector<vector<int>>& ans, vector<int> &order, int& org_k, int k, int n, int min){
		if(k == 1){
			if(min <= n && n < 10){
				order[org_k-k] = n;
				ans.push_back(order);
			}else if(n < min){
				return false;
			}
		}else{
			bool is_continue = true;
			int i;
			for(i = min; i < 10; ++i){
				order[org_k-k] = i;
				is_continue = backtrack(ans,order,org_k, k-1,n-i,i+1);
				if(!is_continue){
					break;
				}
			}
			if(!is_continue && i == min){
				return false;
			}
		}
		return true;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> ans;
		vector<int> order(k, 0);
		backtrack(ans, order, k, k, n, 1);
		return ans;
	}
};
int main() {
	Solution sln;
	vector<vector<int>> ans = sln.combinationSum3(3, 15);
	for(auto& row : ans){
		for(auto i : row){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
