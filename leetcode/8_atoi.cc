/*
 * =====================================================================================
 *
 *       Filename:  8_atoi.cc
 *
 *    Description:  string to integer
 *
 *        Version:  1.0
 *        Created:  03/06/2015 04:59:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdio.h>

#include<climits>
#include<string>
using namespace std;

class Solution{
	public:
		int atoi(string str){
			const int under_max = INT_MAX / 10;
			int i, ans, size, signal;
			ans = 0;
			signal = 1;
			size = str.size();
			for(i = 0; i < size && str[i] == ' '; ++i)
			{}
			if(str[i] == '+')
			{
				signal = 1;
				i++;
			}
			else if(str[i] == '-')
			{
				signal = -1;
				i++;
			}

			for(; i < size; ++i)
			{
				if('0' <= str[i] && str[i] <= '9')
				{
					if(ans > under_max || 
						(str[i]-'0') > (INT_MAX - ans*10))
					{
						if(signal == 1)
							return INT_MAX;
						else
							return INT_MIN;
					}
					ans = ans * 10 + (str[i] - '0');
				}
				else
					break;
			}
			return signal * ans;
		}
};

int main()
{
	Solution sln;
	string str = "2147483648";
	int ans = sln.atoi(str);
	printf("%d\n", ans);
	return 0;
}
