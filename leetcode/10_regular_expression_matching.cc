/*
 * =====================================================================================
 *
 *       Filename:  10_regular_expression_matching.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/07/2015 10:55:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<string.h>

class Solution{
	public:
		bool isMatch(const char *s, const char *p){
			int i, j, s_length, p_length;
			s_length = strlen(s);
			p_length = strlen(p);

			bool signal[s_length+1][p_length+1];

			signal[0][0] = true;

			for(i = 0; i < s_length; ++i)
				signal[i+1][0] = false;

			for(i = 0; i < p_length; ++i)
				signal[0][i+1] = i > 0 && p[i] == '*' && signal[0][i-1];

			for(i = 0; i < s_length; ++i)
			{
				for(j = 0; j < p_length; ++j)
				{
					if(p[j] != '*')
						signal[i+1][j+1] = signal[i][j] && (s[i] == p[j] || p[j] == '.');
					else
					{
						signal[i+1][j+1] = (j > 0 && signal[i+1][j-1]) || signal[i+1][j]
							|| (j > 0 && signal[i][j+1] &&('.' == p[j-1] || s[i] == p[j-1]));
					}
				}
			}
			return signal[s_length][p_length];
		}
};

int main()
{
	Solution sln;
	const char *s = "aab";
	const char *p = ".a*b";
	bool ans = sln.isMatch(s, p);
	printf("%d\n", ans);
	return 0;
}
