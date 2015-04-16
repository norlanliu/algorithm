/*
 * =====================================================================================
 *
 *       Filename:  137_single_number2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2015 09:43:44 PM
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
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int mask;
		int i, j, ans=0;
		for(i = 0; i < 32; ++i){
			mask = 0;
			for(j = 0; j < n; ++j){
				if((A[j]>>i)&1)
					mask++;
			}
			ans |= (mask%3)<<i;
		}
		return ans;
    }
};
int main(){
	int A[7] = {1,1,1,5,5,5,6};
	Solution sln;
	int ans = sln.singleNumber(A, 7);
	cout<<ans<<endl;
	return 0;
}
