/*
 * =====================================================================================
 *
 *       Filename:  66_plus_one.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 07:27:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
#include<iostream>
using namespace std;

class Solution{
	public:
		vector<int> plusOne(vector<int>& digits){
			int i, carry, tmp;
			carry = 1;
			for(i = digits.size()-1; i >= 0; --i){
				tmp = digits[i] + carry;
				if(tmp >= 10){
					carry = 1;
					tmp -= 10;
				}else
					carry = 0;
				digits[i] = tmp;
			}
			if(carry)
				digits.insert(digits.begin(), 1);
			return digits;
		}
};
int main(){
	Solution sln;
	int i;
	vector<int> digits;
	digits.push_back(1);
	for(i = 1; i < 10; ++i){
		cout<<i;
		//digits.push_back(9);
	}
	cout<<endl;
	vector<int> ans = sln.plusOne(digits);
	for(auto i : ans)
		cout<<i;
	cout<<endl;
	return 0;
}
