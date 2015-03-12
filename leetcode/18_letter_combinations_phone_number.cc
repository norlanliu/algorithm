/*
 * =====================================================================================
 *
 *       Filename:  18_letter_combinations_phone_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2015 11:05:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
	public:
		unsigned int GetTotalLength(string digits){
			const int SIZE79 = 4, SIZE268 = 3, SIZE01 = 1;
			unsigned int i, ans, size = digits.size();
			ans = 1;
			for(i = 0; i < size; ++i)
			{
				switch(digits[i])
				{
					case '0':
					case '1':
						ans *= SIZE01;
						break;
					case '7':
					case '9':
						ans *= SIZE79;
						break;
					default:
						ans *= SIZE268;
				}
			}
			return ans;
		}
		vector<string> letterCombinations(string digits){
			if(digits.size() == 0)
				return vector<string>();
			const char LETTERS[10][4] = {  {}, {},
				{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
				{'j', 'k', 'l'}, {'m', 'n', 'o'},
				{'p','q','r','s'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}
			};
			const int SIZE79 = 4, SIZE268 = 3;
			unsigned int i, j, k, x, size, front, length;
			const char* tmp;
			length = GetTotalLength(digits);
			front = 1;
			vector<string> ret(length, "");
			size = digits.size();
			for(i = 0; i < size; ++i)
			{
				switch(digits[i])
				{
					case '0':
					case '1':
						for(auto& it : ret)
							it += ' ';
						break;
					case '7':
					case '9':
						length /= SIZE79;
						tmp = LETTERS[digits[i]-'0'];
						for(x = 0; x < front; ++x)
						{
							for(j = 0; j < SIZE79; ++j)
							{
								for(k = 0; k < length; ++k)
								{
									ret[(x * SIZE79 + j)*length + k] += tmp[j];
								}
							}
						}
						front *= SIZE79;
						break;
					default:
						length /= SIZE268;
						tmp = LETTERS[digits[i]-'0'];
						for(x = 0; x < front; ++x)
						{
							for(j = 0; j < SIZE268; ++j)
							{
								for(k = 0; k < length; ++k)
								{
									ret[(x * SIZE268 + j)*length + k] += tmp[j];
								}
							}
						}
						front *= SIZE268;
				}
			}
			return ret;
		}
};

int main()
{
	Solution sln;
	string digits = "79";
	vector<string> ans = sln.letterCombinations(digits);
	for(auto& it : ans)
	{
		cout<<it<<endl;
	}
	return 0;
}
