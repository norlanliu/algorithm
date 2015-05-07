/*
 * =====================================================================================
 *
 *       Filename:  153_find_minimum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/07/2015 08:01:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i, size;
        size = nums.size() - 1;
        for(i = 0; i < size && nums[i] <= nums[i+1]; ++i){}
		if(i == size)
			return std::min(nums[0], nums[size]);
        return nums[i+1];
    }
};
