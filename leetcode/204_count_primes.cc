/*
 * =====================================================================================
 *
 *       Filename:  204_count_primes.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/18/2015 02:21:33 PM
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
#include <string.h>
#include <iostream>
using namespace std;
class Solution {
	bool judgePrime(int n){
		if(n < 2){
			return false;
		}
		int max = (int)sqrt(n);
		for(int i = 2; i <= max; ++i){
			if(n % i == 0){
				return false;
			}
		}
		return true;
	}
public:
    int countPrimes_bak(int n) {
		if (n < 3){
			return 0;
		}else if (n < 5){
			return n - 2;
		}
		int ans = 2;
		for(int i = 4; i < n; ++i){
			if(i % 2 == 0 || i % 3 == 0){
				continue;
			}else if(judgePrime(i)){
				ans += 1;
			}
		}
		return ans;
    }
    int countPrimes(int n) {
		if (n < 3){
			return 0;
		}
		int ans = n >> 1; 
		int sn = (int)sqrt(n-1);
		bool* signal = new bool[n];
		int i, j, step;
		memset(signal, 0, n);
		sn += 1;
		for(i = 3; i < sn; i += 2){
			if(!signal[i]){
				for(j = i * i, step = i << 1; j < n; j += step){
					if(!signal[j]){
						ans -= 1;
						signal[j] = true;
					}
				}
			}
		}
		delete []signal;
		return ans;
	}
};

int main(){
	Solution sln;
	cout<<sln.countPrimes(100)<<endl;
	return 0;
}
