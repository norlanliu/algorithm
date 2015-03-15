/*
 * =====================================================================================
 *
 *       Filename:  31_next_permutation.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/15/2015 11:09:44 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		void nextPermutation(vector<int> &num){
			int i;
			vector<int>::iterator upper;
			i = num.size()-1;
			for(;i > 0 && num[i-1] >= num[i]; --i){}
			std::reverse(num.begin() + i, num.end());
			if(i != 0){
				i -= 1;
				upper = std::upper_bound(num.begin() + i + 1, num.end(), num[i]);
				swap(*upper, num[i]);
			}
		}
};

int main()
{
	vector<int> nums = {1,2};
	for(auto& it: nums)
		cout<<it<<" ";
	cout<<endl;
	Solution sln;
	sln.nextPermutation(nums);
	for(auto& it: nums)
		cout<<it<<" ";
	cout<<endl;
	return 1;
}
