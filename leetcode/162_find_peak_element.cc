/*
 * =====================================================================================
 *
 *       Filename:  162_find_peak_element.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/19/2015 09:39:01 PM
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
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		int head = 0, middle, next, tail=nums.size()-1;
		while(head < tail) {
			middle = (head + tail) / 2;
			next = middle + 1;

			if( nums[middle] >= nums[next] )
				tail = middle;
			else
				head = next;
		}
		return head;
    }
};

int main() {
	Solution sln;
	vector<int> nums = {1,2,3,2,1,5,6,7,8,9};
	cout<<sln.findPeakElement(nums)<<endl;
	return 0;

}
