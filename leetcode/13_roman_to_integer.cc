/*
 * =====================================================================================
 *
 *       Filename:  13_roman_to_integer.cc
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
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution{
	public:
		int getNum(char c){
			switch(c){
				case 'I':
					return 1;
					break;
				case 'V':
					return 5;
					break;
				case 'X':
					return 10;
					break;
				case 'L':
					return 50;
					break;
				case 'C':
					return 100;
					break;
				case 'D':
					return 500;
					break;
				case 'M':
					return 1000;
					break;
			}
			return 0;
		}
		int romanToInt(string s){
			int i, ans, length, tmp, prev;
			length = s.length();
			ans = 0;
			prev = getNum(s[0]);
			for(i = 1; i < length; ++i)
			{
				tmp = getNum(s[i]);
				if(prev >= tmp)
					ans += prev;
				else
				{
					ans += tmp - prev;
					i++;
				}
				prev = getNum(s[i]);
			}
			if(i == length)
				ans += prev;
			return ans;
		}
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
	int x = 1999;
	string ans = sln.intToRoman(x);
	int integer = sln.romanToInt(ans);
	cout<<integer<<":"<<ans<<endl;
	return 0;
}
