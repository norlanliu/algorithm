/*
 * =====================================================================================
 *
 *       Filename:  242_valid_anagram.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2015 09:50:08 PM
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
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if(s.size() != t.size())
			return false;
		int record[26];
		memset(record, 0, sizeof(int)*26);
		for(auto it = s.begin(); it != s.end(); ++it){
			record[*it-'a'] += 1;
		}
		for(auto it = t.begin(); it != t.end(); ++it){
			record[*it-'a'] -= 1;
		}
		for(int i = 0; i < 26; ++i){
			if(record[i] != 0){
				return false;
			}
		}
		return true;
	}
};

int main(){
	Solution sln;
	string s("anagram");
	cout<<sln.isAnagram(s, "nagaram")<<endl;
	cout<<s<<endl;
	return 0;
}
