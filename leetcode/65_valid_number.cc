/*
 * =====================================================================================
 *
 *       Filename:  65_valid_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/20/2015 04:09:13 PM
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
#include <string>
#include <iostream>
using namespace std;

//
//integer: 1 001 0
//float: .1  1. 0. .0
//signal-integer: +integer -integer
//signal-float: +float -float
//scientific: integer+e+integer, float+e+integer,
//            integer+e+signal-integer, float+e+signal-integer,
//            signal-integer+e+interger, signal-integer+e+signal-integer
//            signal-float+e+integer, signal-float+e+signal-integer

//method:
// judge the relation among first, +/-, dot, e, last.
class Solution {
std::string trim(const std::string& str,
                 const std::string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

public:
    bool isNumber(string s) {
       s = trim(s);
	   if(s.size() == 0){
		   return false;
	   }
	   char c;
	   int i = 0, size = s.size();
	   bool dot = false, se = false, is_signal = false;
	   //check notation
	   if(s[i] == '+' || s[i] == '-'){
		   i++;
		   is_signal = true;
		   if(size == 1){
			   return false;
		   }
	   }
	   for(;i < size; i++) {
		   c = s[i];
		   if(!isdigit(c)) {
			   if(c == 'e' && i != 0 && !se) {
				   //check scientific notation
				   if(dot && (1 == i || (is_signal && i == 2))) {
					   return false;
				   }
				   if(is_signal && i == 1) {
					   return false;
				   }
				   //check scientific notation
				   if(i < size-1) {
					   if(s[i+1] == '-' || s[i+1] == '+') {
						   i++;
						   if(i == size-1){
							   return false;
						   }
					   }
				   } else {
					   return false;
				   }
				   se = true;
			   }else if(c == '.' && !se && !dot){
				   if(is_signal && 2 == size){
					   return false;
				   }
				   if(size == 1){
					   return false;
				   }
				   dot = true;
			   }else{
				   return false;
			   }
		   }
	   }
	   return true;
    }
};
int main(){
	string s = "2e0";
	Solution sln;
	cout<<sln.isNumber(s)<<endl;
	return 0;
}
