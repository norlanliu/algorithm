/*
 * =====================================================================================
 *
 *       Filename:  152_maximum_product_subarray.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/28/2015 05:11:43 PM
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
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.size() == 0){
			return 0;
		}
		int max = 1, min = 1;
		int ret = nums[0], first, second;
		for_each(nums.begin(), nums.end(), [&](int n){
				first = n * min;
				second = n * max;
				if(first < second){
					min = first < n ? first : n;
					max = second > n ? second : n;
				}else{
					min = second < n ? second :  n;
					max = first > n ? first : n;
				}
				if(max > ret){
					ret = max;
				}
			});
		return ret;
    }
};

int main(){
	vector<int> nums = {1 , 3, -2, 4, 2};
	Solution sln;
	cout<<sln.maxProduct(nums)<<endl;
	return 0;
}
