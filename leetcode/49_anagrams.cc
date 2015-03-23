/*
 * =====================================================================================
 *
 *       Filename:  49_anagrams.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2015 02:28:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>

#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution{
	public:
		vector<string> anagrams(vector<string> &strs){
			int i, j, size;
			vector<string> ans;
			string tmp;
			unordered_map<string, int> map;
			size = strs.size();
			bool marks[size];
			memset(marks, 0, size);
			for(i = 0; i < size; ++i){
				tmp = strs[i];
				std::sort(tmp.begin(), tmp.end());
				if(map[tmp] != 0){
					ans.push_back(strs[i]);
					j = map[tmp]-1;
					if(!marks[j])
						ans.push_back(strs[j]);
					marks[j] = true;
				}
				else{
					map[tmp] = i+1;
				}
			}
			return ans;
		}
};

int main(){
	vector<string> strs = {"ate", "hehe", "eheh", "tea", "haha", "heeh", "eta"};
	Solution sln;
	vector<string> ans = sln.anagrams(strs);
	for(auto &it : ans){
		cout<<it<<endl;
	}
	return 0;
}
