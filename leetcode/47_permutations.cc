/*
 * =====================================================================================
 *
 *       Filename:  46_permutations.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 12:32:28 PM
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

class Solution{
	public:
		void EnumPermute(vector<int>& num, unsigned int start, vector<vector<int> >& ans){
			unsigned int size = num.size();
			if(start == size-1){
				ans.push_back(num);
				return;
			}
			unsigned int j;
			int prev, tmp;
			EnumPermute(num, start+1, ans);
			prev = num[start];
			for(j = start+1; j < size; ++j){
				if(prev != num[j]){
					tmp = num[j];
					num.erase(num.begin()+j);
					num.insert(num.begin()+start, tmp);
					EnumPermute(num, start+1, ans);
					num.erase(num.begin()+start);
					num.insert(num.begin()+j, tmp);
					prev = num[j];
				}
			}
		}
		vector<vector<int> > permuteUnique(vector<int>& num){
			vector<vector<int> > ans;
			std::sort(num.begin(), num.end());
			if(num.size() != 0)
				EnumPermute(num, 0, ans);
			return ans;
		}
};

int main()
{
	vector<int> num = {0,1,0,0,9};
	Solution sln;
	vector<vector<int> > ans = sln.permuteUnique(num);
	for(auto& it : ans){
		for(auto i : it)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
