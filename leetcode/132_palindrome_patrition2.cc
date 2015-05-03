/*
 * =====================================================================================
 *
 *       Filename:  131_palindrome_patrition.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/30/2015 09:57:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

/*
 * DP
 * vec[i] 表示0-(i-1)字串的最小切割数
 */
class Solution {
public:
    int minCut(string s) {
		if(s.size() == 0)
			return 0;
		int i, j, size;
		size = s.size();
        int vec[size+1];
		for(i = 0; i <= size; ++i){
			vec[i] = i-1;
		}
		for(i = 0; i != size; ++i){
			for(j = 0; i+j < size && i-j >=0 && s[i-j]==s[i+j]; ++j)
				vec[i+j+1] = min(vec[i+j+1], vec[i-j] + 1);
			for(j = 1; i+j < size && i-j+1 >=0 && s[i-j+1]==s[i+j]; ++j)
				vec[i+j+1] = min(vec[i+j+1], vec[i-j+1] + 1);
		}
		return vec[size];
	}
};

int main(){
	string s = "aa";
	Solution sln;
	int ans = sln.minCut(s);
	cout<<ans<<endl;
	return 0;
}
