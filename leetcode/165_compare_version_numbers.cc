/*
 * =====================================================================================
 *
 *       Filename:  165_compare_version_numbers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/05/2015 06:04:10 PM
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
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
	inline size_t iszero(string c){
		int size = c.size()-1;
		int ret = c.size();
		while(size >= 0 && (c[size] == '0' || c[size] == '.')){
			if(c[size] == '.')
				ret = size;
			size--;
		}
		return ret;
	}
public:
    int compareVersion(string version1, string version2) {
		size_t pos = iszero(version1);
		version1.erase(pos);
		pos = iszero(version2);
		version2.erase(pos);
		
		if(version1.compare(version2) == 0)
			return 0;
	   size_t s1 = version1.size();
	   size_t s2 = version2.size();
	   if(s1 == 0 && s2 == 0){
		   return 0;
	   }else if(s1 == 0){
		   return -1;
	   }else if(s2 == 0){
		   return 1;
	   }
	   std::string::size_type sz1, sz2;
	   int num1 = stoi(version1, &sz1);
	   int num2 = stoi(version2, &sz2);
	   while(num1 == num2 && sz1 < s1 && sz2 < s2){
		   version1 = version1.substr(sz1+1);
		   version2 = version2.substr(sz2+1);
		   s1 = version1.size();
		   s2 = version2.size();
		   num1 = stoi(version1, &sz1);
		   num2 = stoi(version2, &sz2);
	   }
	   if(num1 > num2){
		   return 1;
	   }else if(num1 < num2){
		   return -1;
	   }else{
		   if(sz1 == s1 && sz2 == s2){
			   return 0;
		   }else if(sz1 >= s1){
			   return -1;
		   }else{
			   return 1;
		   }
	   }
    }
};

int main(){
	string version1 = "0.1.010";
	string version2 = "0.10.00.0";
	Solution sln;
	cout<<sln.compareVersion(version1, version2)<<endl;
	return 0;
}
