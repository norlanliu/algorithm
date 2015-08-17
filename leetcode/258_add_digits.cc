/*
 * =====================================================================================
 *
 *       Filename:  258_add_digits.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2015 10:39:29 PM
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
    int addDigits(int num) {
		if(num == 0)
			return 0;
		int ret = num % 9;
		if(ret == 0)
			return 9;
		return ret;
    }
};
