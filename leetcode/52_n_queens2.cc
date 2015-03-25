/*
 * =====================================================================================
 *
 *       Filename:  51_n_queens.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2015 07:13:47 PM
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
		void NQueens(int level, int left, int middle, int right, int n, int& num){
			if(level >= n){
				num++;
				return;
			}
			int mask = left | middle | right;
			for(int i = 0, b = 1; i < n; b <<= 1, ++i){
				if(!(mask&b)){
					NQueens(level+1, (left | b)>>1, middle | b, (right | b) << 1, n, num);
				}
			}
		}
		int totalNQueens(int n){
			int ans = 0;
			NQueens(0, 0, 0, 0, n, ans);
			return ans;
		}
};

int main(){
	int n  = 8;
	Solution sln;
	int ans = sln.totalNQueens(n);
	cout<<ans<<endl;
	return 0;
}
