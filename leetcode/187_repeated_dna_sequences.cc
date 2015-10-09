/*
 * =====================================================================================
 *
 *       Filename:  187_repeated_dna_sequences.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2015 04:19:56 PM
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
#include <math.h>
#include<vector>
#include<string>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences_bak(string s) {
        vector<string> ans;
		unordered_set<int> map;
		unsigned int seed = 7;
		unsigned int value = pow(seed, 9);
		unsigned int hash = 0;
		int size = s.size();
		if(size < 10){
			return ans;
		}
		vector<int> c2i(26, 0);
		c2i[0] = 1;
		c2i['C'-'A'] =  2;
		c2i['G'-'A'] =  3;
		c2i['T'-'A'] =  4;
		string str = s;
		int i = 0;
		for(; i < 10; ++i){
			str[i] = c2i[str[i]-'A'];
			hash = hash * seed + str[i];
		}
		map.insert(hash);
		for(; i < size; ++i){
			hash -= str[i-10]*value;
			str[i] = c2i[str[i]-'A'];
			hash = hash * seed + str[i];
			if(map.find(hash) != map.end()){
				ans.push_back(s.substr(i - 9, 10));
			}else{
				map.insert(hash);
			}
		}
		std::sort(ans.begin(), ans.end());
		auto it = std::unique(ans.begin(), ans.end());
		ans.resize(std::distance(ans.begin(), it));

		return ans;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
		unordered_set<int> map;
		unsigned int holder = 0;
		unsigned int mask = 0xfffff;
		int size = s.size();
		if(size < 10){
			return ans;
		}
		vector<int> c2i(26, 0);
		c2i[0] = 1;
		c2i['C'-'A'] =  2;
		c2i['G'-'A'] =  3;
		c2i['T'-'A'] =  4;
		int i = 0;
		for(; i < 10; ++i){
			holder <<= 2;
			holder += c2i[s[i]-'A'];
		}
		map.insert(holder);
		for(; i < size; ++i){
			holder <<= 2;
			holder &= mask;
			holder += c2i[s[i]-'A'];
			if(map.find(holder) != map.end()){
				ans.push_back(s.substr(i - 9, 10));
			}else{
				map.insert(holder);
			}
		}
		std::sort(ans.begin(), ans.end());
		auto it = std::unique(ans.begin(), ans.end());
		ans.resize(std::distance(ans.begin(), it));

		return ans;
    }
};
int main(){
	Solution sln;
	string str = "AAAAAAAAAAAA";
	vector<string> ans = sln.findRepeatedDnaSequences(str);
	for(auto& s : ans){
		cout<<s<<endl;
	}
	return 0;
}
