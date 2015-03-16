/*
 * =====================================================================================
 *
 *       Filename:  32_longest_valid_parentheses.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/2015 11:04:16 PM
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
#include<stack>
#include<iostream>
using namespace std;

/*
 * DP
 * OPT(i)表示以s[i]结尾的valid字符串的长度
 *           OPT(i-1) + 2 + OPT[stack.top()] if s[i] == ')' && top() == '('
 * OPT(i) =  OPT(i-1) if s[i] == '(' && s[i-1] == ')'
 *           0
 */
class Solution{
	public:
		int longestValidParentheses(string s){
			int i, j, length, max;
			stack<int> indexes;
			length = s.length();
			if(length == 0)
				return 0;
			int valid_length[length];
			memset(valid_length, 0, length * sizeof(int));
			max = 0;
			if(s[0] == '(')
				indexes.push(0);
			for(i = 1; i < length; ++i){
				switch(s[i]){
					case ')' :
						if(! indexes.empty()){
							j = indexes.top();
							if(j == i-1)
								valid_length[i] = valid_length[i-1] + 2;
							else
								valid_length[i] = valid_length[j] + valid_length[i-1] + 2;
							indexes.pop();
						}else{
							valid_length[i] = 0;
						}
						break;
					case '(':
						if(s[i-1] == '(')
							valid_length[i] = 0;
						else
							valid_length[i] = valid_length[i-1];
						indexes.push(i);
				}
				if(valid_length[i] > max)
					max = valid_length[i];
			}
			return max;
		}
};

int main(){
	string s = "(()(()()((())";
	Solution sln;
	int ans = sln.longestValidParentheses(s);
	cout<<s<<endl;
	cout<<ans<<endl;
	return 0;
}
