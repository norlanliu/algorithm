/*
 * =====================================================================================
 *
 *       Filename:  128_longest_consecutive_sequence.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2015 09:49:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		int j, tmp, longest = 0;
		unordered_map<int, bool> map(nums.size());
		for(auto i : nums){
			map[i] = true;
		}
		for(auto i : nums){
			if(map.find(i) != map.end() && map[i]){
				j = 1;
				tmp = i+1;
				while(map.find(tmp) != map.end()){
					map[tmp] = false;
					tmp++;
					j++;
				}
				tmp = i-1;
				while(map.find(tmp) != map.end()){
					map[tmp] = false;
					tmp--;
					j++;
				}
				if(j > longest)
					longest = j;
			}
		}
		return longest;
    }
};

int main(){
	vector<int> nums = {100, 4, 101, 1, 3, 2, 102, 99, 103};
	Solution sln;
	cout<<sln.longestConsecutive(nums)<<endl;
	return 0;
}
