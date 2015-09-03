/*
 * =====================================================================================
 *
 *       Filename:  228_summary_ranges.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2015 03:01:23 PM
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
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if(nums.size() == 0){
			return ans;
		}
        int start, counter;
		start = nums[0];
		counter = start;
		for(auto i : nums){
			if(i == counter){
				counter++;
			}else{
				counter -= 1;
				if(counter == start){
					ans.push_back(to_string(start));
				}else{
					ans.push_back(to_string(start) + "->" + to_string(counter));
				}
				start = i;
				counter = start+1;
			}
		}
		counter -= 1;
		if(counter == start){
			ans.push_back(to_string(start));
		}else{
			ans.push_back(to_string(start) + "->" + to_string(counter));
		}
		return ans;
    }
};
int main(){
	vector<int> nums = {0,2,4,7};
	Solution sln;
	vector<string> ans = sln.summaryRanges(nums);
	for(auto str: ans){
		cout<< str<<endl;
	}
	return 0;
}
