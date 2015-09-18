/*
 * =====================================================================================
 *
 *       Filename:  minimum_size_subarray_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/18/2015 04:43:52 PM
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
#include <stdint.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int size = nums.size();
		if(size == 0){
			return 0;
		}
		int head = 0, sum = nums[0], length, ret = size;
		if(sum >= s){
			return 1;
		}else{
			length = 1;
		}
		for(auto iter = nums.begin()+1; iter != nums.end(); ++iter){
			while(sum - nums[head] + *iter >= s){
				sum -= nums[head];
				head++;
				length--;
			}
			length += 1;
			sum += *iter;
			if(sum >= s && length < ret){
				ret = length;
			}
		}
		return sum >= s ? ret : 0;
    }
};
int main(){
	vector<int> nums = {5,1,3 ,5,10,7,4,9,2,8};
	Solution sln;
	cout<<sln.minSubArrayLen(15, nums)<<endl;
	return 0;
}
