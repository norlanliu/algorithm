/*
 * =====================================================================================
 *
 *       Filename:  87_scamble_string.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 08:57:32 AM
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
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class Solution{
	inline bool StringWithSameCharacters(string s1, string s2){
		int chars[CHAR_MAX];
		memset(chars, 0, CHAR_MAX*sizeof(int));
		int chars_mask[CHAR_MAX];
		memset(chars_mask, 0, CHAR_MAX*sizeof(int));
		for(auto s : s1){
			chars[(int)s]++;
		}
		for(auto s : s2){
			chars[(int)s]--;
		}
		return memcmp(chars, chars_mask, CHAR_MAX*sizeof(int)) == 0;
	}
	bool recursion(string s1, string s2){
			int i, half_size, size;
			bool is_duplicate;
			string tmp[3];
			size = s1.size();
			if(size < 4)
				return true;
			half_size = (size + 1) / 2;
			for(i = 1; i <= half_size; ++i){
				tmp[0] = s1.substr(0, i);
				tmp[1] = s2.substr(0, i);
				is_duplicate = false;
				if(StringWithSameCharacters(tmp[0], tmp[1])){
					is_duplicate = true;
					if(recursion(tmp[0], tmp[1]) && recursion(s1.substr(i, size-i),
							s2.substr(i, size-i)))
						return true;
				}
				tmp[2] = s2.substr(size-i, i);
				if(StringWithSameCharacters(tmp[0], tmp[2])){
					is_duplicate = true;
					if(recursion(tmp[0], tmp[2]) && recursion(s1.substr(i, size-i),
							s2.substr(0, size-i)))
						return true;
				}
				if(is_duplicate)
					return false;
				tmp[0] = s1.substr(size-i, i);
				if(StringWithSameCharacters(tmp[0], tmp[1])){
					is_duplicate = true;
					if(recursion(tmp[0], tmp[1]) && recursion(s1.substr(0, size-i),
							s2.substr(i, size-i)))
						return true;
				}
				if(StringWithSameCharacters(tmp[0], tmp[2])){
					is_duplicate = true;
					if(recursion(tmp[0], tmp[2]) && recursion(s1.substr(0, size-i),
							s2.substr(0, size-i)))
						return true;
				}
				if(is_duplicate)
					return false;
			}
			return false;
	}
	public:
		bool isScramble(string s1, string s2){
			if(!StringWithSameCharacters(s1, s2))
				return false;
			return recursion(s1, s2);
		}
};

int main(){
	Solution sln;
	bool ans = sln.isScramble("hobobyrqd", "hbyorqdbo");
	cout<<ans<<endl;
	return 0;
}
