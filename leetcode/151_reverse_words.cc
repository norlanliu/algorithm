/*
 * =====================================================================================
 *
 *       Filename:  151_reverse_words.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2015 09:37:02 AM
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
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
	inline void ReverseWord(string& word, int start, int end){
		int half = (end - start) / 2;
		int i;
		char tmp;
		for(i = 0; i <= half; ++i){
			tmp = word[start+i];
			word[start+i] = word[end - i];
			word[end - i] = tmp;
		}
	}
public:
    void reverseWords(string &s) {
    	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        std::reverse(s.begin(), s.end());
        size_t start = s.find(" ", 0);
		size_t count = 0, i = start; 
		while(i != std::string::npos){
			if(s[i] == ' '){
				count++;
				i++;
			}else{
				s.erase(start, count-1);
				start = s.find(" ", start+1);
				count = 0;
				i = start;
			}
		}
		start = 0;
        size_t end = s.find(" ", start);
        while(end != std::string::npos){
        	ReverseWord(s, start, end-1);
        	start = end+1;
        	end = s.find(" ", start);
        }
        if(start < s.length())
        	ReverseWord(s, start, s.length()-1);
    }
};

int main(){
	string str = "   a     bd  cdfs  ";
	Solution sln;
	sln.reverseWords(str);
	cout<<str<<endl;
	return 0;
}
