/*
 * =====================================================================================
 *
 *       Filename:  14_longest_common_prefix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/10/2015 08:33:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<climits>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
	public:
		string longestCommonPrefix_old(vector<string> &strs){
			string ans;
			char character;
			unsigned int i, min_length;
			min_length = strs.size() == 0 ? 0 : INT_MAX;
			for(auto str : strs){
				if(str.length() < min_length)
					min_length = str.length();
			}
			for(i = 0; i < min_length; ++i)
			{
				character = strs[0][i];
				for(auto str : strs){
					if(str[i] != character)
						return ans;
				}
				ans += character;
			}
			return ans;
		}
		string longestCommonPrefix(vector<string> &strs){
			if(strs.size() == 0)
				return "";
			string tmp;
			bool result;
			int left, right, middle;
			unsigned int min_length;
			min_length = INT_MAX;
			for(auto str : strs){
				if(str.length() < min_length)
					min_length = str.length();
			}
			left = 0;
			right = min_length - 1;
			while(left <= right){
				result = true;
				middle = (left + right) / 2;
				tmp = strs[0].substr(left, middle - left + 1);
				for(auto str : strs){
					if(tmp.compare(str.substr(left, middle - left + 1)) != 0)
					{
						result = false;
						break;
					}
				}
				if(result)
					left = middle + 1;
				else
					right = middle - 1;
			}
			return strs[0].substr(0, left);
		}
};

int main()
{
	vector<string> strs = {"floor"};
	Solution sln;
	string ans = sln.longestCommonPrefix(strs);
	cout<<ans<<endl;
	return 0;
}
