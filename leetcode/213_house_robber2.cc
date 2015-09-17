/*
 * =====================================================================================
 *
 *       Filename:  213_house_robber2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2015 09:31:29 AM
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
		}else if(size == 1){
			return nums[0];
		}
		int i, f1, f2, f3, s1, s2, s3;
		f1 = nums[0];
		f2 = nums[0];
		s1 = 0;
		s2 = nums[1];
		for(i = 2; i < size; i++){
			f3 = max(f2, f1+nums[i]);
			f1 = f2;
			f2 = f3;
			s3 = max(s2, s1+nums[i]);
			s1 = s2;
			s2 = s3;
		}
		return s2 > f1 ? s2 : f1;
    }
};
