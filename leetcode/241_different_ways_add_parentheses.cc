/*
 * =====================================================================================
 *
 *       Filename:  241_different_ways_add_parentheses.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/08/2015 03:28:38 PM
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
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
	vector<int> EnumParentheses(vector<int> &nums, vector<char> &ops, int start,
			int end) {
		vector<int> ans;
		if(start == end){
			ans.push_back(nums[start]);
			return ans;
		}
		vector<int> left , right;
		for(int i = start; i < end; ++i){
			left = EnumParentheses(nums, ops, start, i);
			right = EnumParentheses(nums, ops, i+1, end);
			for(auto j : left){
				for(auto k : right){
					switch(ops[i]){
						case '+':
							ans.push_back(j + k);
							break;
						case '-':
							ans.push_back(j - k);
							break;
						case '*':
							ans.push_back(j * k);
							break;
					}
				}
			}
		}
		return ans;
	}
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> nums;
		vector<char> ops;
		int i, last = 0, size = input.size();
		for(i = 0 ; i < size; ++i){
			if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
				ops.push_back(input[i]);
				nums.push_back(atoi(input.substr(last, i-last).c_str()));
				last = i+1;
			}
		}
		nums.push_back(atoi(input.substr(last, i-last).c_str()));
		return EnumParentheses(nums, ops, 0, ops.size());
	}
};

int main(){
	string ops = "2*3-4";
	Solution sln;
	vector<int> ans = sln.diffWaysToCompute(ops);
	for(auto i : ans){
		cout<<i<<endl;
	}
	return 0;
}
