/*
 * =====================================================================================
 *
 *       Filename:  268_missing_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/30/2015 08:49:01 PM
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
#include <algorithm>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = 0;
		int sum = 0;
		bool zero = false;
        for_each(nums.begin(), nums.end(), [&](int i){
            if(i > max){
                max = i;
			}
			if(i == 0){
				zero = true;
			}
			sum += i;
        });
		if(!zero){
			return 0;
		}
		max += 1;
		if(max == nums.size()){
			return max; 
		}
        return (max * (max - 1)) / 2 - sum;
    }
};
