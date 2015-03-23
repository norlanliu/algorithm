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
		void NQueens(vector<string> str, int row, int n, vector<vector<string> >& ans){
			const static char offense = 'x';
			const static char double_offense = 'X';
			const static char queen = 'Q';
			const static char dot = '.';
			int i, j, k;
			for(i = 0; i < n; ++i){
				if(str[row][i] != offense && str[row][i] != double_offense){
					str[row][i] = queen;
					for(j = row+1, k = 1; j < n; j++, k++){
						if(i - k >= 0){
							if(str[j][i-k] == offense)
								str[j][i - k] = double_offense;
							else if(str[j][i-k] == dot)
								str[j][i - k] = offense;
						}
						if(str[j][i] == offense)
							str[j][i] = double_offense;
						else if(str[j][i] == dot)
							str[j][i] = offense;
						if(i + k < n){
							if(str[j][i+k] == offense)
								str[j][i + k] = double_offense;
							else if(str[j][i+k] == dot)
								str[j][i + k] = offense;
						}
					}
					if(row == n-1){
						ans.push_back(str);
						return;
					}
					NQueens(str, row+1, n, ans);
					for(j = row+1, k = 1; j < n; j++, k++){
						if(i - k >= 0 && str[j][i-k] == offense)
							str[j][i - k] = dot;
						if(str[j][i] == offense)
							str[j][i] = dot;
						if(i + k < n && str[j][i+k] == offense)
							str[j][i + k] = dot;
					}
					str[row][i] = dot;
				}
			}
		}
		vector<vector<string> > solveNQueens(int n){
			const static char dot = '.';
			const static char queen = 'Q';
			string s(n, dot);
			vector<string> str(n, s);
			vector<vector<string> > ans;
			NQueens(str, 0, n, ans);
			for(auto& it : ans){
				for(auto &str : it){
					for(auto& i : str)
						if(i != queen)
							i = dot;
				}
			}
			return ans;
		}
};

int main(){
	int n  = 9;
	Solution sln;
	vector<vector<string> > ans = sln.solveNQueens(n);
	for(auto& it : ans){
		for(auto str : it){
			cout<<str<<endl;
		}
		cout<<endl;
	}
	cout<<ans.size()<<endl;
	return 0;
}
