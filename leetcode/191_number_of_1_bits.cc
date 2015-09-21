/*
 * =====================================================================================
 *
 *       Filename:  191_number_of_1_bits.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/21/2015 08:40:50 PM
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
#include <inttypes.h>
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ret = 0;
		uint32_t mask = 1, lmask = 0x80000000;
		for(int i = 0; i != 16; ++i){
			ret += ((n & mask) == 0 ? 0 : 1) + ((n & lmask) == 0 ? 0 : 1);
			mask <<= 1;
			lmask >>= 1;
		}
		return ret;
    }
};
