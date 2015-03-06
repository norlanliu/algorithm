/*
 * =====================================================================================
 *
 *       Filename:  7_reverse_integer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2015 09:08:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

class Solution{
	public:
		int reverse(int x){
			const int under_max = INT_MAX / 10;
			int ans = 0;

			while(x != 0)
			{
				if(ans > under_max || ans < -under_max)
					return 0;
				ans = ans * 10 + x % 10;
				x /= 10;
			}
			return ans;
		}
};

int main()
{
	Solution sln;
	int a = -12300;
	int ans = sln.reverse(a);
	printf("%d, %x, %d\n", a, a, ans);
	return 0;
}
