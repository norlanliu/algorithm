/*
 * =====================================================================================
 *
 *       Filename:  29_divide_two_integers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2015 08:11:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<climits>
#include<iostream>
using namespace std;

class Solution{
	public:
		int divide(int dividend, int divisor){
			typedef long long ll;
			if(divisor == 0)
				return INT_MAX; 
			int k, m;
			ll i, j, ans, abs_dividend, abs_divisor;
			bool flag = dividend < 0 ^ divisor < 0 ? true : false;
			ans = 1;
			abs_dividend = abs((ll)dividend);
			abs_divisor = abs((ll)divisor);
			i = abs_dividend; 
			j = abs_divisor;
			if(i < j)
				return 0;
			while((j<<1) <= abs_dividend){
				j <<= 1;
				ans <<= 1;
			}
			i = abs_dividend - j;
			k = j >> 1;
			m = ans >> 1;
			while(i >= abs_divisor){
				if(j+k > abs_dividend)
				{
					k = k >> 1;
					m = m >> 1;
				}
				else
				{
					ans += m;
					i -= k;
					j += k;
				}
			}
			if(flag)
				return  -ans;
			return ans > INT_MAX ? INT_MAX :  ans;
		}
};
int main()
{
	Solution sln;
	int dividend, divisor;
	dividend = INT_MIN;
	divisor = 1;
	int ans = sln.divide(dividend, divisor);
	cout<<ans<<endl;
}
