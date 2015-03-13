/*
 * =====================================================================================
 *
 *       Filename:  22_generate_parentheses.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2015 07:17:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
	public:
		void recursiveParenthesis(vector<string>& vec, int n, int m, string str){
			if(m == 0 && n == 0)
			{
				vec.push_back(str);
				return;
			}
			if(n > 0)
				recursiveParenthesis(vec, n-1, m+1, str + '(');
			if(m > 0)
				recursiveParenthesis(vec, n, m-1, str + ')');
		}
		vector<string> generateParenthesis(int n){
			vector<string> ans;
			recursiveParenthesis(ans, n, 0, "");
			return ans;
		}
};

int main()
{
	Solution sln;
	vector<string> ans = sln.generateParenthesis(3);
	for(auto& it : ans)
		cout<<it<<endl;
	return 0;
}
