/*
 * =====================================================================================
 *
 *       Filename:  11_container_with_most_water.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2015 11:51:38 PM
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
		int maxArea(vector<int> &height){
			int left, right, max;
			max = 0;
			left = 0;
			right = height.size();
			while(left < right)
			{
				max = std::max(max, (right-left)* std::min(height[left], height[right]));
				if(height[left] < height[right])
					left++;
				else
					right--;
			}
			return max;
		}
};

int main(){
	vector<int> vec = {2};
	Solution sln;
	int max = sln.maxArea(vec);
	cout<<max<<endl;
	return 0;
}
