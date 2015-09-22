/*
 * =====================================================================================
 *
 *       Filename:  201_bitwise_and_of_numbers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2015 01:48:45 PM
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
#include <stdio.h>
#include <stdint.h>
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		if(n == 0){
			return 0;
		}
		int ret = 0;
		uint32_t mask = 0x80000000;
		while((mask&n) == 0){
			mask >>= 1;
		}
		while((mask & m) == (mask & n) && mask != 0){
			ret += (mask & n);
			mask >>= 1;
		}
		return ret;
    }
};
int main() {
	Solution sln;
	printf("%x\n", sln.rangeBitwiseAnd(0x80000000,0x80000000));
	return 0;
}
