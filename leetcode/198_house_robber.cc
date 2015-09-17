/*
 * =====================================================================================
 *
 *       Filename:  198_house_robber.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/2015 09:57:02 PM
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
#include <algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		if(size == 0){
			return 0;
		}else if (size == 1){
			return nums[0];
		}
		nums[1] = nums[0] >= nums[1] ? nums[0] : nums[1];
		for(int i = 2; i < size; ++i){
			nums[i] = max(nums[i-1], nums[i]+nums[i-2]);
		}
		return nums[size-1];
	}
};
