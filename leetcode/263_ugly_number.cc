/*
 * =====================================================================================
 *
 *       Filename:  263_ugly_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/31/2015 09:44:45 PM
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
    bool isUgly(int num) {
		if(num < 1){
			return false;
		}
		int primes[] = {2, 3, 5};
		int j = 0;
		for(int i = 0; i < 3 && num != 1; i++){
			j = primes[i];
			while(num % j == 0){
				num /= j;
			}
		}
		return num == 1;
    }
};

int main(){
	Solution sln;
	cout <<sln.isUgly(14)<<endl;
	return 0;
}
