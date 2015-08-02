/*
 * =====================================================================================
 *
 *       Filename:  164_max_gap.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2015 10:30:42 AM
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
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		int size = nums.size();
		if(size < 2)
			return 0;
		int scale = 10;
		int buckets[scale][size];
		int buckets_index[scale];

		int max_length = 0;
		int i, j, k, tmp = 0;
		int ratio = 1, max = 0;

		for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
			if(*iter > max)
				max = *iter;
		}
		while(max != 0) {
			max_length++;
			max /= 10;
		}

		while(max_length) {
			memset(buckets_index, 0, 10 * sizeof(int));
			k = 0;
			for(auto iter = nums.begin(); iter != nums.end(); ++iter) {
				tmp = (*iter / ratio) % scale;
				buckets[tmp][buckets_index[tmp]] = *iter;
				buckets_index[tmp]++;
			}
			for(i = 0; i < scale; ++i) {
				tmp = buckets_index[i];
				for(j = 0; j < tmp; ++j) {
					nums[k++] = buckets[i][j];
				}
			}
			ratio *= scale;
			max_length--;
		}

		int ret = 0;

		for(i = 1; i != size; ++i) {
			tmp = nums[i] - nums[i-1];
			if(tmp > ret)
				ret = tmp;
		}
	
		return ret;
    }
};

int main() {
	vector<int> nums = {1,10000};
	Solution sln;
	cout<<"max: " <<sln.maximumGap(nums)<<endl;
	for_each(nums.begin(), nums.end(), [](int k){
			cout<<k<<endl;
			});
	return 0;
}
