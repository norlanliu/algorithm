/*
 * =====================================================================================
 *
 *       Filename:  168_excel_sheet.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2015 08:57:48 PM
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
#include<string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
		string res;
		char tmp;
		while(n) {
			n -= 1;
			tmp = 'A' + n % 26;
			res = tmp + res;
			n /= 26;
		}
        return res;
    }
};
int main(){
	Solution sln;
	cout<<sln.convertToTitle(26)<<endl;
	return 0;
}
