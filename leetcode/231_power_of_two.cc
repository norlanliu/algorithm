/*
 * =====================================================================================
 *
 *       Filename:  231_power_of_two.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2015 02:32:52 PM
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
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n <= 0){
			return false;
		}
		int length = sizeof(int) * 8;
		int mask = 1;
		bool is_power = false;
		for(int i = 0; i < length; ++i){
			if((n & mask) != 0){
				if(!is_power){
					is_power = true;
				}else{
					return false;
				}
			}
			mask <<= 1;
		}
		return true;
    }
};
int main(){
	Solution sln;
	cout<<sln.isPowerOfTwo(1<<31)<<endl;
	return 0;
}
