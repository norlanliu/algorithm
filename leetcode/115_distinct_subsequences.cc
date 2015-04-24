/*
 * =====================================================================================
 *
 *       Filename:  115_distinct_subsequences.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2015 10:38:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string.h>
#include<iostream>
#include<string>
using namespace std;

/*
 * DP:
 * count[i][j]: 表示以i为起点的s的字串和以j为起点的t的字串中不相同的
 *				字串的数量
 */
class Solution {
public:
    int numDistinct(string s, string t) {
		size_t i, prev, found, si;
		int ti;
		si = s.size();
		ti = t.size();
		int count[si+1][ti+1];
		for(i = 0; i <= si; ++i){
			memset(count[i], 0, (ti+1)*sizeof(int));
			count[i][ti] = 1;
		}
		prev = si;
		for(ti -= 1; ti >= 0; ti--){
			found = s.find_last_of(t[ti], si);
			if(found != string::npos)
				si = found;
			while(found != string::npos){
				count[found][ti] += count[prev][ti] + count[found+1][ti+1];
				for(i = found+1; i < prev; ++i)
					count[i][ti] = count[prev][ti];
				prev = found;
				if(found == 0)
					break;
				found = s.find_last_of(t[ti], found-1);
			}
			for(i = 0; i < prev; ++i)
				count[i][ti] = count[prev][ti];
		}
		return count[0][0];
	}
};

int main(){
	Solution sln;
	string s = "rarabbbitra";
	string t = "rabbit";
	cout<<sln.numDistinct(s, t)<<endl;
	return 0;
}
