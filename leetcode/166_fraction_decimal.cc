/*
 * =====================================================================================
 *
 *       Filename:  166_fraction_decimal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2015 04:27:54 PM
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
#include <string>
#include <unordered_map>
#include <complex>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		int i;
		long integer, remainder, new_den, tmp;
		int left = -1;
		unordered_map<int, int> map;
		string ret;
		string str = "";
		if((double)numerator / denominator < 0 ) {
			ret = "-";
		}
		remainder = std::abs((long)numerator);
		new_den = std::abs((long)denominator);
		integer = remainder / new_den;
		ret.append(to_string(integer));
		remainder = remainder % new_den;
		if(remainder == 0)
			return ret;
		i = 0;
		while(true){
			tmp = remainder * 10;
			integer = tmp / new_den;
			remainder = tmp % new_den;
			if(remainder == 0) {
				str.push_back(integer + '0');
				break;
			}
			tmp = remainder * 10 + integer;
			if(map.find(tmp) != map.end()) {
				left = map[tmp];
				break;
			}else {
				map[tmp] = i;
			}
			str.push_back(integer + '0');
			i++;
		}

		if(left != -1) {
			str.insert(left, 1, '(');
			str.push_back(')');
		}
		ret.push_back('.');
		ret.append(str);

		return ret;
    }
};

int main() {
	Solution sln;
	cout<<sln.fractionToDecimal(-50, 8)<<endl;
	return 0;
}
