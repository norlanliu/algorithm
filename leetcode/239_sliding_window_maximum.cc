/*
 * =====================================================================================
 *
 *       Filename:  239_sliding_window_maximum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2015 08:52:16 PM
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
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> queue;
		int i, size;
		size = nums.size();
		for(i = 0; i < size; ++i){
			if(!queue.empty() && queue.front() == i-k){
				queue.pop_front();
			}
			while(!queue.empty() && nums[queue.back()] < nums[i]){
				queue.pop_back();
			}
			queue.push_back(i);
			if(i >= k-1){
				ans.push_back(nums[queue.front()]);
			}
		}
		return ans;
	}
};

int main(){
	vector<int> nums = {9,10,9,-7,-4,-8,2,-6};
	Solution sln;
	vector<int> ans = sln.maxSlidingWindow(nums, 5);
	for(auto i : ans){
		cout<<i<<endl;
	}
	return 0;
}
