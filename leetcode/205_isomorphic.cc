/*
 * =====================================================================================
 *
 *       Filename:  205_isomorphic.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/23/2015 11:00:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		char maps[128] = {0};
		char mapt[128] = {0};
		int size = s.size();
		for(int i = 0; i != size; ++i){
			if(maps[(int)s[i]] != 0 && maps[(int)s[i]] != t[i]){
					return false;
			}else if(mapt[(int)t[i]] != 0 && mapt[(int)t[i]] != s[i]){
					return false;
			}else{
				maps[(int)s[i]] = t[i];
				mapt[(int)t[i]] = s[i];
			}
		}
		return true;
	}
	bool isIsomorphic_bak(string s, string t) {
		unordered_map<char,char> maps;
		unordered_map<char,char> mapt;
		int size = s.size();
		for(int i = 0; i < size; ++i){
			if(maps.find(s[i]) != maps.end() && maps[s[i]] != t[i]){
					return false;
			}else if(mapt.find(t[i]) != mapt.end() && mapt[t[i]] != s[i]){
					return false;
			}else{
				maps[s[i]] = t[i];
				mapt[t[i]] = s[i];
			}
		}
		return true;
	}
};
int main(){
	Solution sln;
	cout<<sln.isIsomorphic("foo","baa")<<endl;
	return 0;
}
