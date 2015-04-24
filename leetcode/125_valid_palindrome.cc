/*
 * =====================================================================================
 *
 *       Filename:  125_valid_palindrome.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2015 09:46:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>
using namespace std;
class Solution{
	public:
		bool isPalindrome(string s){
			int i, j;
			for(i = 0, j = s.size()-1; i < j;){
				while(i < j && !isalnum(s[i]))
					i++;
				while(i < j && !isalnum(s[j]))
					j--;
				if(tolower(s[i]) != tolower(s[j]))
					return false;
				i++;
				j--;
			}
			return true;
		}
};

int main(){
	string s = " aA";
	Solution sln;
	cout<<sln.isPalindrome(s)<<endl;
	return 0;
}
