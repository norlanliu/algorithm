/*
 * =====================================================================================
 *
 *       Filename:  20_valid_parentheses.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2015 09:32:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string>
#include<stack>
#include<iostream>
using namespace std;

class Solution{
	public:
		bool isValid(string s){
			stack<char> fronts;
			char back;
			for(auto& it : s){
				switch(it)
				{
					case ')':
						back = '(';
						break;
					case ']':
						back = '[';
						break;
					case '}':
						back = '{';
						break;
					default:
						fronts.push(it);
				}
				switch(it)
				{
					case ')':
					case ']':
					case '}':
						if(fronts.size() != 0 && fronts.top() == back)
							fronts.pop();
						else 
							return false;
						break;
				}
			}
			return (fronts.size() == 0);
		}
};

int main()
{
	string str = "}";
	Solution sln;
	bool ans = sln.isValid(str);
	cout<<ans<<endl;
	return 0;
}
