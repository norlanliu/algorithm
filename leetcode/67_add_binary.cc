/*
 * =====================================================================================
 *
 *       Filename:  67_add_binary.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 07:40:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>
using namespace std;

class Solution{
	public:
		string addBinary(string a, string b){
			const char str11 = '1' + '1';
			string ans;
			int i, j, end, carry; 
			char k;
			carry = 0;
			end = a.size() > b.size() ? a.size() : b.size();
			ans.resize(end);
			end -= 1;
			i = a.size() - 1;
			j = b.size() - 1;
			string& longer = i > j ? a : b;
			for(; i >= 0 && j >= 0; --i, --j){
				k = a[i] + b[j] + carry;
				if(k >= str11){
					carry = 1;
					k -= str11;
					k += '0';
				}else{
					carry = 0;
					k -= '0';
				}
				ans[end--] = k;
			}
			while(end >= 0){
				k = longer[end] + carry;
				if(k > '1'){
					carry = 1;
					k = '0';
				}else{
					carry = 0;
				}
				ans[end--] = k;
			}
			if(carry)
				ans = '1' + ans;
			return ans;
		}
};

int main(){
	Solution sln;
	string a = "11", b = "101011";
	string ans = sln.addBinary(a, b);
	cout<<a<<"+"<<b<<"="<<ans<<endl;
	return 0;
}
