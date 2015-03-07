/*
 * =====================================================================================
 *
 *       Filename:  8_palindrome_number.cc
 *
 *    Description:  Judge whether an integer is palindrome number
 *
 *        Version:  1.0
 *        Created:  03/06/2015 07:54:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include<cmath>

class Solution{
	public:
		bool isPalindrome(int x){
			if(x < 0)
				return false;
			const int decimal = 10;
			int i, front, num;
			i = 0;
			num = x;
			while(num != 0)
			{
				i++;
				num /= decimal;
			}
			front = (int)pow(decimal, i-1);
			num = x;
			
			for(i /= 2; i > 0; --i)
			{
				if((num / front) != (x % decimal))
					return false;
				num = num % front;
				front /= decimal;
				x /= decimal;
			}
			return true;
		}
};

int main()
{
	Solution sln;
	int x = 112;
	bool ans = sln.isPalindrome(x);
	printf("%d\n", ans);
	return 0;
}
