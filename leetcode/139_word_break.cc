/*
 * =====================================================================================
 *
 *       Filename:  139_word_break.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/2015 09:13:25 PM
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
#include<iostream>
using namespace std;

/*
 * DP
 * exist[i] 表示从i开始的到S结尾的字串中是否可以划分.
 */
class Solution{
	string s;
	unsigned int _min_size;
	unsigned int _max_size;
	unsigned int _size;
	bool check(int start, unordered_set<string>& word_dict, bool* exists){
		if(s.size() < start + _min_size || exists[start])
			return false;
		unsigned int i, max;
		max = (start + _max_size < s.size() ? _max_size : s.size()-start)+1;
		for(i = _min_size; i != max; i++){
			unordered_set<string>::const_iterator got = word_dict.find(s.substr(start, i));
			if(got != word_dict.end()){
				if((start+i) == s.size() || check(start + i, word_dict, exists))
					return true;
				exists[start+i] = true;
			}
		}
		return false;
	}
	public:
		bool wordBreak(string s, unordered_set<string>& wordDict){
			bool exists[s.size()];
			memset(exists, 0, s.size());
			this->s = s;
			_size = s.size();
			_min_size = INT_MAX;
			_max_size = 0;
			for(auto& str : wordDict){
				if(str.size() < _min_size)
					_min_size = str.size();
				if(str.size() > _max_size)
					_max_size = str.size();
			}
			return check(0, wordDict, exists);
		}
};

int main(){
	string s = "dogs";
	unordered_set<string> word_dict = {"dog", "s", "gs"};
	Solution sln;
	cout<<sln.wordBreak(s, word_dict)<<endl;
	return 0;
}
