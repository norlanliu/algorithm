/*
 * =====================================================================================
 *
 *       Filename:  219_contains_dupilcate2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2015 08:32:15 PM
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
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> set;
		int size = nums.size();
		if(size <= k){
			k = size-1;
		}
		int i = 0;
		while(i <= k){
			if(set.find(nums[i]) != set.end()){
				return true;
			}
			set.insert(nums[i]);
			i++;
		}
		
		for(;i < size; ++i){
			set.erase(nums[i-k-1]);
			if(set.find(nums[i]) != set.end()){
				return true;
			}
			set.insert(nums[i]);
		}

		return false;
	}
	bool containsNearbyDuplicate_old(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		int size = nums.size();
		for(int i = 0; i < size; ++i){
			if(map.find(nums[i]) != map.end()){
				if(i - map[nums[i]] <= k){
					return true;
				}
			}
			map[nums[i]] = i;
		}
		return false;
	}
};

int main(){
	Solution sln;
	vector<int> nums = {1,2,3,4,54,1,5};
	cout<<sln.containsNearbyDuplicate(nums, 4)<<endl;
	return 0;
}
