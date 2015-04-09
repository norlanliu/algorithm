/*
 * =====================================================================================
 *
 *       Filename:  90_subsets2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2015 07:04:08 PM
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
#include<algorithm>
using namespace std;

class Solution {
	vector<vector<int> > ans;
    vector<int> data;
    int _size;
	void Enum(vector<int>& S, int start, int length){
		if(length == 0){
			ans.push_back(data);
			return;
		}
		int i, prev, size;
		prev = !S[start];
		size = _size - length;
		for(i = start; i != size; ++i){
			if(S[i] != prev){
				data.push_back(S[i]);
				Enum(S, i+1, length-1);
				data.pop_back();
			}
			prev = S[i];
		}
	}
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		int i;
		std::sort(S.begin(), S.end());
		_size = S.size() + 1;
		for(i = 0; i != _size; ++i){
			Enum(S, 0, i);
		}
		return ans;
    }
};

int main(){
	Solution sln;
	vector<int> S = {1,3,3,2,2};
	vector<vector<int> > ans = sln.subsetsWithDup(S);
	for(auto& it : ans){
		for(auto i : it)
			cout<<i<<",";
		cout<<endl;
	}
	return 0;
}
