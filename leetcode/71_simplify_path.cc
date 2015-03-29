/*
 * =====================================================================================
 *
 *       Filename:  71_simplify_path.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2015 08:14:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>
#include<stack>
using namespace std;

class Solution{
	public:
		string simplifyPath(string path){
			unsigned int i, j, k;
			stack<int> slash;
			char prev;
			path += '/';
			string ans = path;
			j = 0;
			k = 0;
			prev = '*';
			for(i = 0; i < path.size(); ++i){
				switch(path[i]){
					case '/':
						if(prev != '/' && prev != '.'){
							ans[j++] = '/';
							slash.push(j);
						}else if(prev == '.'){
							if(k == 1){
								j -= 1;
							}
							else if(k == 2){
								if(slash.top() > 1){
									slash.pop();
								}
								j = slash.top();
							}
							k = 0;
						}
						break;
					case '.':
						ans[j++] = path[i];
						k++;
						break;
					default :
						ans[j++] = path[i];
						if(prev == '.')
							k = 0;
				}
				prev = path[i];
			}
			if(j > 1 && ans[j-1] == '/')
				j--;
			return ans.substr(0, j);
		}
};

int main(){
	string path = "/home/.x/../.k/...";
	Solution sln;
	string ans = sln.simplifyPath(path);
	cout<<ans<<endl;
	return 0;
}
