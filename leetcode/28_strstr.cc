/*
 * =====================================================================================
 *
 *       Filename:  28_strstr.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2015 03:35:57 PM
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
		int strStr(char* haystack, char* needle){
			if(needle == NULL || haystack == NULL)
				return -1;
			int i, j, k, needle_length, haystack_length;
			needle_length = strlen(needle);
			haystack_length = strlen(haystack);

			if(needle_length == 0 && haystack_length == 0)
				return 0;

			int back[needle_length];
			memset(back, 0, needle_length * sizeof(int));
			for(i = 1, k = 0; i < needle_length; ++i)
			{
				if(needle[i] == needle[k]){
					if(k == j)
						k = 0;
					back[i] = k;
					k++;
				}
				else{
					j = i+1;
					back[i] = k;
					k = 0;
				}
			}

			for(i = 0, j = 0; i < haystack_length && j < needle_length;)
			{
				if(haystack[i] == needle[j]){
					i++;
					j++;
				}
				else{
					if(j == 0)
						i++;
					else
						j = back[j];
				}
			}
			if(j == needle_length)
				return i - j;
			else
				return -1;
		}
};

int main()
{
	char* haystack = "strstrstrastraing";
	char* needle = "strstra"; 
	Solution sln;
	int ans = sln.strStr(haystack, needle);
	cout<<ans<<endl;
	return 0;
}
