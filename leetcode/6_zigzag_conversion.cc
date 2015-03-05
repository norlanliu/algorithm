/*
 * =====================================================================================
 *
 *       Filename:  6_zigzag_conversion.cc
 *
 *    Description:  Zigzag conversion
 *
 *        Version:  1.0
 *        Created:  03/05/2015 10:04:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdio.h>

#include<string>
using namespace std;

class Solution{
	public:
		string convert(string s, int nRows){
			int i, j, k;
			int column_gap, gap, size;
			string ans(s.size(), 0);
			size = s.size();
			column_gap = 2 * nRows - 2;
			k = 0;

			if(column_gap == 0)
				return s;

			for(i = 0; i < nRows; ++i)
			{
				ans[k++] = s[i];
				gap = 2 * (nRows - i -1);
				j = i;
				while((j+gap) < size)
				{
					if(gap != column_gap && gap != 0)
					{
						ans[k++] = s[j + gap];
					}
					j += column_gap;
					if(j < size)
						ans[k++] = s[j];
				}
			}
			return ans;
		}
};

int main()
{
	Solution sln;
	string s = "P";
	string ans = sln.convert(s, 1);
	printf("%s\n", ans.c_str());
	return 0;
}
