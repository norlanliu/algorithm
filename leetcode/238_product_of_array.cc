/*
 * =====================================================================================
 *
 *       Filename:  238_product_of_array.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/11/2015 03:38:01 PM
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
    vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		int tmp = 1;
		vector<int> ret(size, 1);
		for(int i = 1; i < size; ++i){
			ret[i] = ret[i-1] * nums[i-1];
		}
		for(int i = size - 2; i >= 0; --i){
			tmp *= nums[i+1];
			ret[i] = ret[i] * tmp;
		}
		return ret;
    }
};

int main(){
	vector<int> nums = {2, 0, 4};
	Solution sln;
	vector<int> ans = sln.productExceptSelf(nums);
	for_each(ans.begin(), ans.end(), [](int i){
			cout<<i<<endl;
			});
	return 0;
}
