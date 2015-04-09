/*
 * =====================================================================================
 *
 *       Filename:  84_largest_rectangle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2015 07:57:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		unsigned int ret = 0, h;
		int idx;
		height.push_back(0);
		vector<int> index;
		for(unsigned int i = 0 ; i != height.size(); ++i){
			while(index.size() != 0 && height[index.back()] >= height[i]){
				h = height[index.back()];
				index.pop_back();

				idx = index.size() == 0 ? -1 : index.back();
				if(h * (i - idx - 1) > ret)
					ret = h * (i - idx - 1);
			}
			index.push_back(i);
		}
		return ret;
	}
	int largestRectangleArea_old(vector<int> &height) {
		if(height.size() == 0)
			return 0;
		unsigned i;
		int j, local_min, ans, asc, tmp, prev;
		vector<int> area(height.size(), 0);
		local_min = 0;
		ans = height[0];
		area[0] = height[0];
		asc = true;
		for(i = 1; i != height.size(); ++i){
			if(!asc && height[i] >= height[i-1])
				local_min = i - 1;
			if(height[i] != height[i-1])
				asc = height[i] > height[i-1];
			if(asc){
				prev = 0;
				for(j = i-1; j >= local_min; --j){
					tmp = height[j] * (i - j) + area[j];
					if(tmp < prev)
						break;
					prev = tmp;
					if(tmp > ans)
						ans = tmp;
				}
				area[i] = height[i];
			}else{
				for(j = local_min; j != (i-1) && height[j] < height[i]; j++){
					tmp = height[j] * (i - j) + area[j];
					if(tmp > ans)
						ans = tmp;
				}
				area[i] = height[i] * (i - j) + area[j];
				if(area[i] > ans){
					ans = area[i];
				}
			}
		}
		return ans;
	}
};

int main(){
	Solution sln;
	vector<int> height = {2, 1, 5,6,2,3};
	int ans  = sln.largestRectangleArea(height);
	cout<<ans<<endl;
	return 0;
}
