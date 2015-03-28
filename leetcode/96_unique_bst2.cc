/*
 * =====================================================================================
 *
 *       Filename:  unique_bst2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 08:49:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>
#include<iostream>
using namespace std;
/*
 * dp: mark[i][j] : 表示从i到j二叉数的个数
 *
 * mark[i][j] = mark[i][j-1] + mark[i+1][j] +
 *              mark[i][k-1]*mark[k+1][j]; ( i<k<j )
 */
class Solution {
public:
	int numTrees(int n){
		//backtracking method
		//return enumBST(1, n);
		int i, j, k;
		int** mark = (int**)malloc(sizeof(int*) * (n+1));
		n += 1;
		for(i = 0; i < n; ++i){
			mark[i] = (int*)malloc(sizeof(int) * n);
			memset(mark[i], 0, sizeof(int)*n);
			mark[i][i] = 1;
		}
		for(i = n-2; i > 0; --i){
			for(j = i + 1; j < n; ++j){
				mark[i][j] += mark[i][j-1] + mark[i+1][j];
				for(k = i + 1; k < j; ++k){
					mark[i][j] += mark[i][k-1] * mark[k+1][j];
				}
			}
		}
		k = mark[1][n-1];
		for(i = 0; i < n; ++i){
			delete mark[i];
		}
		delete mark;
		return k;
	}
};

int main(){
	Solution sln;
	int ans = sln.numTrees(3);
	cout<<ans<<endl;
	return 0;
}
