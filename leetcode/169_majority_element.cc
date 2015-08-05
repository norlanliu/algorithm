/*
 * =====================================================================================
 *
 *       Filename:  169_majority_element.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2015 10:33:02 PM
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
#include <math.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		int middle = floor(nums.size() / 2.0);
		unordered_map<int, int> map;
		for(auto iter = nums.begin(); iter != nums.end(); ++iter){
			if(map.find(*iter) == map.end()){
				map[*iter] = 1;
			}else{
				map[*iter] += 1;
			}
			if(map[*iter] > middle)
				return *iter;
		}
    }
};

int main() {

}
