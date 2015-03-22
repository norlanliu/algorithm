/*
 * =====================================================================================
 *
 *       Filename:  length_of_last_word.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 09:24:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>

#include<iostream>
using namespace std;

class Solution{
	public:
		int lengthOfLastWord(const char* s){
			if(s == NULL)
				return 0;
			int i, ans = 0;
			int length = strlen(s) - 1;
			i = length;
			while(i >= 0 && s[i] == ' ')
				i--;
			while(i >= 0 && s[i] != ' '){
				ans++;
				--i;
			}
			return ans;
		}
		int lengthOfLastWord_old(const char* s){
			const char* seperator = " ";
			int length = strlen(s) + 1;
			char str[length];
			char* ans = NULL,* cur;
			strncpy(str, s, length);
			cur = strtok(str, seperator);
			while(cur != NULL){
				ans = cur;
				cur = strtok(NULL, seperator);
			}
			if(ans != NULL)
				return strlen(ans);
			else
				return 0;
		}
};
int main(){
	const char* str = "1af 23e ";
	Solution sln;
	int ans = sln.lengthOfLastWord(str);
	cout<<ans<<endl;
	return 0;
}
