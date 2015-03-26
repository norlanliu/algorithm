/*
 * =====================================================================================
 *
 *       Filename:  60_permutation_sequence.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 06:54:29 PM
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
#include<vector>
using namespace std;

class Solution{
	public:
		string getPermutation(int n, int k){
			string ans;
			int i, j, m;
			int factorial[n+1];
			vector<int> array(n+1, 0);
			factorial[0] = 1;
			for(i = 1; i <= n; ++i){
				factorial[i] = i * factorial[i-1];
				array[i] = i;
			}
			if(k > factorial[i-1] || k < 1)
				return "";
			for(i = 1; i < n; ++i){
				j = n - i;
				if(k % factorial[j] == 0){
					m = k / factorial[j];
				}else{
					m = k / factorial[j] + 1;
				}
				k -= (factorial[j] * (m-1));
				ans += (array[m] + '0');
				array.erase(array.begin() + m);
			}
			ans += (array[1] + '0');
			return ans;
		}
};

int main(){
	Solution sln;
	string ans = sln.getPermutation(9, 1);
	cout<<ans<<endl;
	return 0;
}
