/*
 * =====================================================================================
 *
 *       Filename:  131_palindrome_patrition.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/30/2015 09:57:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
	inline bool isPanlidrome(string str){
		int i, j;
		i = 0; j = str.size()-1;
		while(i < j){
			if(str[i++] != str[j--])
				return false;
		}
		return true;
	}

	string s;
	int size;
	void backtracking(vector<vector<string> >& ans, vector<string> &tmp, int start){
		if(start == size){
			ans.push_back(tmp);
			return;
		}
		int i, m, n;
		for(i = size-1; i >= start; --i){
			m = start; n = i;
			while(m < n && s[m] == s[n]){
				m++;
				n--;
			}
			if(m >= n){
				tmp.push_back(s.substr(start, i - start+1));
				backtracking(ans, tmp, i+1);
				tmp.pop_back();
			}
		}
	}
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string> > ans;
		if(s.size() == 0)
			return ans;
		vector<string> tmp;
		this->s = s;
		this->size = s.size();
		backtracking(ans, tmp, 0);
		return ans;
	}
    vector<vector<string>> partition_old(string s) {
		reverse(s.begin(), s.end());
		int i;
		unsigned j, k, size;
		string str;
		size = s.size();
        vector<vector<string> > vec[size];
		vec[size-1].push_back(vector<string>(1, s.substr(size-1, 1)));
		for(i = size - 2; i >= 0; --i){
			str = string(1, s[i]);
			vec[i].insert(vec[i].begin(), vec[i+1].begin(), vec[i+1].end());
			for(k = 0; k != vec[i+1].size(); ++k){
				vec[i][k].push_back(str);
			}
			for(j = i + 2; j != size; j++){
				str += s[j-1];
				if(isPanlidrome(str)){
					vec[i].insert(vec[i].begin(), vec[j].begin(), vec[j].end());
					for(k = 0; k != vec[j].size(); ++k){
						vec[i][k].push_back(str);
					}
				}
			}
			str += s[j-1];
			if(isPanlidrome(str)){
				vec[i].push_back(vector<string>(1, str));
			}
		}
		return vec[0];
    }
};

int main(){
	string s = "abaaba";
	Solution sln;
	vector<vector<string> > ans = sln.partition(s);
	for(auto & it : ans){
		for(auto & i : it){
			cout<<"\""<<i<<"\""<<",";
		}
		cout<<endl;
	}
	return 0;
}
