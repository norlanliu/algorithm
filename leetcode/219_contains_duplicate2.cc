/*
 * =====================================================================================
 *
 *       Filename:  219_contains_duplicate2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/28/2015 05:05:18 PM
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
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        bool ans = false;
        int i, size;
        size = nums.size();
        for(i = 0; i != size; ++i){
            if(map.find(nums[i]) != map.end()){
                if(i - map[nums[i]] <= k)
                    return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};
