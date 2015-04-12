/*
 * =====================================================================================
 *
 *       Filename:  93_restore_ip_addresses.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 09:13:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution{
	vector<string> _addrs;
	int _size;
	void restore(string& s, int start, int part, string addr){
		if(part == 1){
			if(_size - start > 3 || start == _size)
				return;
			string tmp = s.substr(start, _size-start);
			if((tmp[0] == '0' && tmp.size() > 1) || std::stoi(tmp) > 255)
				return;
			_addrs.push_back(addr+tmp);
			return;
		}
		for(int i = 1; start < (_size-i+1) && i != 4; ++i){
			string tmp = s.substr(start, i);
			if(i == 3 && (tmp[0] > '2' || std::stoi(tmp) > 255))
				return;
			if(tmp[0] != '0' || tmp.size() == 1)
				restore(s, start+i, part-1, addr + tmp  +".");
		}
	}
	public:
		vector<string> restoreIpAddresses(string s){
			_size = s.size();
			string str;
			if(_size < 4 || _size > 12)
				return _addrs;
			restore(s, 0, 4, str);
			return _addrs;
		}
};

int main(){
	Solution sln;
	vector<string> ans = sln.restoreIpAddresses("101023");
	for(auto& i : ans)
		cout<<i<<endl;
	return 0;
}
