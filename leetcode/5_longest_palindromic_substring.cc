/*
 * =====================================================================================
 *
 *       Filename:  5_longest_palindromic_substring.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/04/2015 10:53:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdio.h>

#include <string>
using namespace std;

class Solution{
	public:
		/*
		 * string(i, L) is a substring of s where i is the start index and L is the length
		 * S(n) is the longest palindrome for substring of s with indice from 0 to n
		 *
		 * suppose S(n-1) = string(i, L)
		 *         |-string(n-L, L+1)   if string(n-L, L+1) is palindrome.
		 * S(n) =  |-string(n-L-1, L+2) if string(n-L-1, L+2) is palindrome
		 *         |-S(n-1)
		 *
		 * Proof: The longest palindrome of S(n-1) is L,
		 *        if S(n) is longer than S(n-1), the longest palindrome 
		 *        of S(n) is end of s[n].
		 *        假设新增加的长度为x,因为要满足S(n-1) = L,因此
		 *                          L+x-2 <= L
		 *                            x <= 2
		 */
		string longestPalindrome(string s)
		{
			int i = 0, j = 0, length = 0;
			int str_length = s.length();
			for(j = 0; j < str_length; ++j)
			{
				if(isPalindrome(s, j-length, length+1))
				{
					i = j-length;
					length += 1;
				}
				else if((j-length-1) >= 0 && isPalindrome(s, j-length-1, length+2))
				{
					i = j - length - 1;
					length += 2;
				}
			}
			return s.substr(i, length);

		}

		bool isPalindrome(string s, int index, int length)
		{
			int i, end;
			end = index + length - 1; 
			for(i = index; i < end; ++i, --end)
			{
				if(s[i] != s[end])
					return false;
			}
			return true;
		}
};

int main()
{
	Solution sln;
	string s = "";
	string max = sln.longestPalindrome(s);
	printf("%s\n", max.c_str());
	return 0;
}
