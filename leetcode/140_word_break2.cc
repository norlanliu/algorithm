/*
 * =====================================================================================
 *
 *       Filename:  140_word_break2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/23/2015 08:31:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<string.h>
#include<limits.h>
#include<string>
#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;

/*
 * DP
 * substrs : 保存用于以start为起点的字串的所有的划分
 */

class Solution{
	string s;
	//the min length of word dict
	unsigned int _min_size;
	//the max length of word dict
	unsigned int _max_size;
	bool check(unsigned int start, unordered_set<string>& word_dict, vector<string>* substrs){
		if(start == s.size())
			return true;
		//判断是否到达字符串不可分割的末尾
		if(s.size() < start + _min_size)
			return false;
		//判断字符串是否可以划分
		if(!substrs[start].empty()){
			return substrs[start].size() != 1;
		}
		unsigned int i, max, ans;
		string str;
		//检查是否超过字串的边界
		max = (start+_max_size < s.size() ? _max_size : s.size()-start)+1;
		ans = false;
		for(i = _min_size; i != max; i++){
			str = s.substr(start, i);
			unordered_set<string>::const_iterator got = word_dict.find(str);
			if(got != word_dict.end()){
				if(check(start + i, word_dict, substrs)){
					if(start+i == s.size()){
						substrs[start].push_back(str);
					}else{
						for(auto& it : substrs[start+i]){
							substrs[start].push_back(str+" "+it);
						}
						//弹出用于判断的字串
						substrs[start].pop_back();
					}
					ans = true;
				}
			}
		}
		//用于判断以start为起点的字串是否可以划分
		substrs[start].push_back("");
		return ans;
	}
	public:
		vector<string> wordBreak(string s, unordered_set<string>& wordDict){
			vector<string> substrs[s.size()];
			this->s = s;
			_min_size = INT_MAX;
			_max_size = 0;
			for(auto& str : wordDict){
				if(str.size() < _min_size)
					_min_size = str.size();
				if(str.size() > _max_size)
					_max_size = str.size();
			}
			check(0, wordDict, substrs);
			//弹出用于判断的字符串
			if(!substrs[0].empty())
				substrs[0].pop_back();
			return substrs[0];
		}
};

int main(){
	string s = "catsanddogs";
	unordered_set<string> word_dict = {"cat", "cats", "dogs", "and", "sand"};
	Solution sln;
	vector<string> ans = sln.wordBreak(s, word_dict);
	for(auto str : ans)
		cout<<str<<endl;
	return 0;
}
