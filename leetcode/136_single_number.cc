/*
 * =====================================================================================
 *
 *       Filename:  136_single_number.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2015 11:02:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
	public:
	    int singleNumber(int A[], int n) {
			int ans = 0;
			for_each(A, A+n, [&](int i){
						ans ^= i;
					});
			return ans;
		}

};
int main(){
	int A[] = {-1,-1, 1};
	Solution sln;
	int ans = sln.singleNumber(A,3);
	cout<<ans<<endl;
	return 0;
}
