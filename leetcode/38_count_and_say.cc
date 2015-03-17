/*
 * =====================================================================================
 *
 *       Filename:  36_count_and_say.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/17/2015 08:44:48 AM
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
using namespace std;

class Solution{
	public:
		string countAndSay(int n){
			if(n == 1)
				return "1";
			int i, j, k, size;
			string start = "1.", ans;
			for(i = 1; i < n; ++i){
				k = 1;
				ans = "";
				size = start.length()-1;
				for(j = 0; j < size; ++j){
					if(start[j+1] == start[j]){
						k++;
					}
					else{
						ans += (k + '0');
						ans += start[j];
						k = 1;
					}
				}
				start = ans;
				start += '.';
			}
			return ans;
		}
};

int main()
{
	Solution sln;
	for(int i = 2; i < 10; ++i){
		string ans = sln.countAndSay(i);
		cout<<ans<<endl;
	}
	return 0;
}
