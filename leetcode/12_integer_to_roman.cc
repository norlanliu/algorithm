/*
 * =====================================================================================
 *
 *       Filename:  13_integer_to_roman.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/08/2015 10:55:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution{
	public:
		string intToRoman(int num){
			std::vector<int> scales = {1, 4, 5, 9, 10, 40, 50,
				90, 100, 400, 500, 900, 1000};;
			std::vector<string> table = {"I","IV", "V", "IX", "X", "XL", "L",
					"XC", "C", "CD", "D", "CM", "M"};
			std::vector<int>::iterator tmp;
			int index, last;
			last = scales.size() - 1;
			string ans;
			while(num > 3){
				std::vector<int>::iterator tmp = std::lower_bound(scales.begin(), scales.end(), num);
				if(*tmp == 0)
					index = last;
				else if(*tmp == num)
					index = tmp - scales.begin();
				else
					index = tmp - scales.begin() - 1;
				ans += table[index];
				num -= scales[index];
			}
			ans += string(num, 'I');
			return ans;
		}
};

int main(){
	Solution sln;
	int x = 1998;
	string ans = sln.intToRoman(x);
	cout<<x<<":"<<ans<<endl;
	return 0;
}
