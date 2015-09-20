/*
 * =====================================================================================
 *
 *       Filename:  189_rotate_array.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/20/2015 03:16:25 PM
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
    void rotate1(vector<int>& nums, int k) {
		int size = nums.size();
		if(size <= 1){
			return;
		}
		k %= size;
		int i, tmp, backup, length;
		if((size & 1) == 0){
			length = k <= size / 2 ? k : size - k ;
		}else{
			length = 1;
		}
		for(int j = 0; j < length; ++j){
			i = j + k;
			tmp = nums[j];
			while(i != j){
				backup = nums[i];
				nums[i] = tmp;
				tmp = backup;
				i = (i + k) % size;
			}
			nums[i] = tmp;
		}
    }
    void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		if(size <= 1){
			return;
		}
		k %= size;
		k = size - k;
		std::rotate(nums.begin(), nums.begin()+k, nums.end());
	}
};

int main(){
	vector<int> nums = {1,2,3,4,5,6,7};
	Solution sln;
	sln.rotate(nums, 6);
	for_each(nums.begin(), nums.end(), [&](int i){
			cout<<i<<" ";
			});
	cout<<endl;
	return 0;
}
