/*
 * =====================================================================================
 *
 *       Filename:  62_unique_path.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 11:13:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;

/*
 * 组合问题:从m+n-2中选择n-1个
 */
class Solution{
	public:
		int uniquePaths(int m, int n){
			int i, j, tmp;
			long long k, p;
			tmp = m + n - 2;
			k = 1;
			p = 1;
			j = m < n ? m : n;
			for(i = j-1; i > 0; --i){
				k *= tmp;
				p *= i;
				if(k % p == 0){
					k /= p;
					p = 1;
				}
				tmp -= 1;
			}
			return k;
		}
};

int main(){
	Solution sln;
	int ans = sln.uniquePaths(50, 10);
	cout<<ans<<endl;
	return 0;
}
