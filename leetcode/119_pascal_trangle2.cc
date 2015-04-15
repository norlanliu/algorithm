/*
 * =====================================================================================
 *
 *       Filename:  119_pascal_trangle2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2015 11:55:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
using namespace std;
class Solution{
	public:
		vector<int> getRow(int rowIndex){
			rowIndex += 1;
			vector<int> ans(rowIndex, 1);
			if(rowIndex < 3)
				return ans;
			int i, j, m, n;
			m = 1;
			for(i = 2; i != rowIndex; ++i){
				for(j = 1; j != i; ++j){
					n = ans[j];
					ans[j] += m;
					m = n;
				}
			}
			return ans;
		}
};
