/*
 * =====================================================================================
 *
 *       Filename:  190_reverse_bits.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/21/2015 08:04:00 PM
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
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		uint32_t ret = 0, mask = 1, rmask = 0x80000000;
		for(int i = 31; i > 0; i -= 2){
			ret += ((n >> i) & mask) + ((n << i) & rmask);
			mask <<= 1;
			rmask >>= 1;
		}
		return ret;
    }
};
int main(){
	uint32_t n = 32768;
	Solution sln;
	cout<<sln.reverseBits(n)<<endl;
	return 0;
}
