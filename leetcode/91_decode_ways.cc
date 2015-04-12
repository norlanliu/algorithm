/*
 * =====================================================================================
 *
 *       Filename:  91_decode_ways.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 10:57:41 AM
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
	int _size;
	int EnumDecodings(string &s, int start){
		if(start > _size || (start == _size && s[start] != '0'))
			return 1;
		int ans = 0;
		if(s[start] == '0')
			return 0;
		if(s[start+1] != '0')
			ans += EnumDecodings(s, start+1);
		if(s[start] == '1' || (s[start] == '2' && s[start+1] < '7'))
			ans += EnumDecodings(s, start+2);
		return ans;
	}
	int Decoding(string& s, int start, int end){
		if(start > end)
			return 1;
		else if(start == end ){
			return s[end] != '0';
		}else if(start == end-1){
			if(s[start] == '0')
				return 0;
			int ans = 0;
			if(s[start] == '1' || (s[start] == '2' && s[end] < '7'))
				ans += 1;
			if(s[end] != '0')
				ans += 1;
			return ans;
		}

		int ans = 0, tmp1 = -1, tmp2 = -1;
		int middle = (start + end) / 2;
		if(s[middle] != '0'){
			tmp1 = Decoding(s, start, middle-1);
			tmp2 = Decoding(s, middle+1, end);
			ans += tmp1 * tmp2;
		}
		if(s[middle-1] == '1' || (s[middle-1] == '2' && s[middle] < '7')){
			if(tmp2 != -1)
				ans += Decoding(s, start, middle-2) * tmp2;
			else
				ans += Decoding(s, start, middle-2) * Decoding(s, middle+1, end);
		}
		if(s[middle] == '1' || (s[middle] == '2' && s[middle+1] < '7'))
			ans += tmp1 * Decoding(s, middle+2, end);
		return ans;
	}
	public:
		int numDecodings(string s){
			if(s.size() == 0 || s[0] == '0')
				return 0;
			return Decoding(s, 0, s.size()-1 );
		}
};
int main(){
	Solution sln;
	cout<<sln.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565")<<endl;
	return 0;
}
