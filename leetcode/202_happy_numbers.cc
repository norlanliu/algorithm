/*
 * =====================================================================================
 *
 *       Filename:  202_happy_numbers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/22/2015 07:59:16 PM
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
#include <unordered_map>
#include <math.h>
#include <stdio.h>
using namespace std;
class Solution {
public:
    bool isHappy_bak(int n) {
		if(n <= 0){
			return false;
		}
		int i = n, j, num;
		unordered_map<int, bool> map;
		while(i != 1){
			map[i] = true;
			j = i;
			i = 0;
			while(j != 0){
				num = j % 10;
				i += pow(num, 2);
				j /= 10;
			}
			if(map.find(i) != map.end()){
				return false;
			}
		}
		return true;
    }
	int calculate(int n){
		int i = 0;
		while(n != 0){
			i += pow(n % 10, 2);
			n /= 10;
		}
		return i;
	}
    bool isHappy(int n) {
		int first = n, second = n;
		do{
			first = calculate(first);
			second = calculate(second);
			second = calculate(second);
		}while(first != 1 && first != second);
		if(first == 1){
			return true;
		}
		return false;
	}
};

int main(){
	Solution sln;
	printf("%d\n", sln.isHappy(19));
	return 0;
}
