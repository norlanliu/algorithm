/*
 * =====================================================================================
 *
 *       Filename:  179_largest_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2015 09:57:03 AM
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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
		int size = nums.size();
		vector<string> str_nums(nums.size(), "");
		for(int i = 0; i < size; ++i){
			str_nums[i] = to_string(nums[i]);
		}
		sort(str_nums.begin(), str_nums.end(), [&](string first, string second){
					return second + first < first + second;
				});
		string ret = "";
		for(auto & str : str_nums){
			ret += str;
		}
		return ret[0] != '0' ? ret : "0";
	}
    string largestNumber_bak(vector<int>& nums) {
		int size = nums.size();
		int max_size = 0;
		vector<string> str_nums(nums.size(), "");
		for(int i = 0; i < size; ++i){
			str_nums[i] = to_string(nums[i]);
			if(str_nums[i].size() > (size_t)max_size){
				max_size = str_nums[i].size();
			}
		}
		vector<int> counter(10, 0);
		vector<string> buckets(size, "");
		int index = 0, tmp;
		for(int i = 0; i < max_size; ++i){
			counter.assign(10, 0);
			for(auto& str : str_nums){
				tmp = max_size - str.size();
				if(i < tmp) {
					index = str[0] - '0';
				}else{
					index = str[max_size - 1 - i] - '0';
				}
				counter[index] += 1;
			}
			for(int j = 1; j < 10; ++j){
				counter[j] += counter[j-1];
			}
			for(auto iter = str_nums.rbegin(); iter != str_nums.rend(); ++iter){
				tmp = max_size - iter->size();
				if(i < tmp) {
					index = (*iter)[0] - '0';
				}else{
					index = (*iter)[max_size - 1 - i] - '0';
				}
				buckets[counter[index] - 1] = *iter;
				counter[index]--;
			}
			for(int j = 0; j < size; ++j){
				str_nums[j] = buckets[j];
			}
		}
		size -= 1;
		for(auto iter = str_nums.rbegin()+1; iter != str_nums.rend(); ++iter){
			str_nums[size] += *iter;
		}
		return str_nums[size];
    }
};

int main(){
	vector<int> nums = {3, 334455, 34, 5, 9};
	Solution sln;
	cout<<sln.largestNumber(nums)<<endl;
	return 0;
}
