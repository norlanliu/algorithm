/*
 * =====================================================================================
 *
 *       Filename:  217_contains_duplicate.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/05/2015 10:34:22 PM
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
	bool containsDuplicate(vector<int>& nums) {
			bool array[0xFFFFF] = {};
			bool withDuplicates = false;
		
			for(int i = 0; i< nums.size(); i++)
			{
				if(array[nums[i]]) {
					withDuplicates = true;
					break;
				}
				else{
					array[nums[i]] = true;
				}
			}
		
			return withDuplicates;
    }
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        auto iter = unique(nums.begin(), nums.end());
        if((iter - nums.begin()) != size) {
            return true;
        }
        return false;
    }
};
