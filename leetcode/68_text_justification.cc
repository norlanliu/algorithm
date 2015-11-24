/*
 * =====================================================================================
 *
 *       Filename:  68_text_justification.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2015 10:58:03 AM
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
#include<vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		if(words.size() == 0 || maxWidth <= 0){
			return words;
		}
		string str;
		int i, j, size = words.size();
		int length = 0, start = 0, tmp;
		int average_space, first_space;
		for(i = 0; i < size; ++i){
			tmp = length + words[i].size() + i - start;
			if(tmp > maxWidth){
				tmp = i - start - 1;
				str = "";
				length = maxWidth - length - tmp;
				if(tmp != 0){
					average_space = length / tmp + 1;
					first_space = length % tmp;
					for(j = start; j < i-1; ++j){
						if(first_space > 0)
							str += words[j]+string(average_space+1, ' ');
						else
							str += words[j]+string(average_space, ' ');
						first_space--;
					}
					str += words[i-1];
				}else{
					str += words[i-1] + string(length, ' ');
				}
				start = i;
				length = 0;
				ans.push_back(str);
			}
			length += words[i].size();
		}
		str = "";
		size -= 1;
		for(i = start; i < size; ++i){
			str += words[i] + " ";
		}
		str += words[i];
		average_space = maxWidth - length - i + start;
		str += string(average_space, ' ');
		ans.push_back(str);
		return ans;
    }
};

int main() {
	vector<string> words = {"Listen","to","many,","speak","to","a","few."};
	Solution sln;
	vector<string> ans = sln.fullJustify(words, 6);
	for(auto str : ans){
		cout<<str<<"@"<<endl;
	}
	return 0;
}
