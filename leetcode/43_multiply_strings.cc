/*
 * =====================================================================================
 *
 *       Filename:  43_multiply_strings.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 10:53:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<regex>
#include<iostream>
#include<string>
using namespace std;

class Solution{
	public:
		string add(string num1, string num2){
			int i, j, k, val, length1, length2, carry;
			length1 = num1.length() - 1;
			length2 = num2.length() - 1;
			k = length1 > length2 ? length1 : length2;
			string ans(k+1, '0');
			carry = 0;
			for(i = length1, j = length2; i >= 0 && j >= 0; --k, --i, --j){
				val = num1[i] - '0' + num2[j] - '0' + carry;
				if(val >= 10){
					carry = 1;
					ans[k]= val - 10 + '0';
				}else{
					carry = 0;
					ans[k] = val + '0';
				}
			}
			while(i >= 0){
				val = num1[i] + carry;
				if(val > '9'){
					carry = 1;
					ans[k] = val - 10;
				}else{
					carry = 0;
					ans[k] = val;
				}
				i--,k--;
			}
			while(j >= 0){
				val = num2[j] + carry;
				if(val >= 10){
					carry = 1;
					ans[k] = val - 10;
				}else{
					carry = 0;
					ans[k] = val;
				}
				j--,k--;
			}
			if(carry == 1)
				ans.insert(ans.begin(),'1');
			return ans;
		}
		string multiply(string num1, string num2){
		//	std::regex pattern("0*");
		//	if(std::regex_match(num1, pattern) || std::regex_match(num2, pattern)){
		//		return "0";
		//	}
			if(num1[0] == '0' || num2[0] == '0')
				return "0";
			int i, j, k, m, val, carry, tmp;
			m = num1.length() + num2.length();
			string ans(m, '0');
			for(i = num1.length()-1; i >= 0; --i){
				carry = 0;
				tmp = num1[i] - '0';
				k = m-1; 
				for(j = num2.length()-1; j >= 0; --j, --k){
					val = tmp * (num2[j] - '0') + carry + ans[k] - '0';
					ans[k] = val % 10 + '0';
					carry = val / 10;
				}
				ans[k] = carry + '0';
				m--;
			}
			if(ans[0] == '0')
				return ans.substr(1, ans.length()-1);
			return ans;
		}
};
int main(){
	Solution sln;
	string num1 = "9999";
	string num2 = "1";
	string ans = sln.add(num1,num2);
	string mans = sln.multiply(num1, num2);
	cout<<num1<<" + "<<num2<<" = "<<ans<<endl;
	cout<<num1<<" * "<<num2<<" = "<<mans<<endl;
	return 0;
}
