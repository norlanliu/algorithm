/*
 * =====================================================================================
 *
 *       Filename:  171_excel_sheet.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/05/2015 09:34:30 PM
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
#include <algorithm>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
		int ret = 0;
        for_each(s.begin(), s.end(), [&](char a){
				ret *= 26;
				ret += a - 'A' + 1;
				});
		return ret;
    }
};
