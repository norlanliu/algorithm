/*
 * =====================================================================================
 *
 *       Filename:  53_max_subarray.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 11:18:10 PM
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

class Solution{
	public:
		int maxSubArray(int A[], int n){
			int i, sum, ans;
			sum = 0;
			ans = 0;
			for(i = 0; i < n; ++i){
				if(sum < 0)
					sum = 0;
				sum += A[i];
				if(sum > ans)
					ans = sum;
			}
			return ans;
		}
};
