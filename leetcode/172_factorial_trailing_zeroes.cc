/*
 * =====================================================================================
 *
 *       Filename:  172_factorial_trailing_zeroes.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/28/2015 07:40:57 PM
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
    int trailingZeroes(int n) {
		int ret = 0;
		for(long long i = 5; n / i > 0; i *= 5){
			ret += (n / i);
		}
		return ret;
    }
};

int main(){
	Solution sln;
	cout<<sln.trailingZeroes(1055)<<endl;
	return 0;
}
