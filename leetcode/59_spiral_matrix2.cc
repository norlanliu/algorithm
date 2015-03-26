/*
 * =====================================================================================
 *
 *       Filename:  59_spiral_matrix2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 02:34:43 PM
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
		vector<vector<int> > generateMatrix(int n){
			vector<int> row(n, 0);
			vector<vector<int> > ans(n, row);
			int i, j, k, num, loop;
			loop = (n - 1) / 2;
			num = 1;
			for(k = 0; k <= loop; ++k){
				for(i = k, j = k; j < n-k; ++j){
					ans[i][j] = num++; 
				}
				for(j -= 1, i += 1; i < n-k; ++i){
					ans[i][j] = num++;
				}
				for(j -= 1, i -= 1; j >= k && i > k; --j){
					ans[i][j] = num++;
				}
				for(j += 1, i -= 1; i > k && j < n-k; --i){
					ans[i][j] = num++;
				}
			}
			return ans;
		}
};

int main(){
	Solution sln;
	vector<vector<int> > ans = sln.generateMatrix(0);
	for(auto& it : ans){
		for(auto i : it){
			cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
