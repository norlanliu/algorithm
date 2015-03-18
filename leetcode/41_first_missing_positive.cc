/*
 * =====================================================================================
 *
 *       Filename:  41_first_missing_positive.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/18/2015 09:25:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdint.h>
#include<limits.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int firstMissingPositive(int A[], int n){
			int i = 0;
			while(i < n){
				if(A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i]){
					std::swap(A[A[i]-1], A[i]);
				}
				else{
					i++;
				}
			}
			for(i = 0; i < n; ++i){
				if(A[i] != i + 1)
					return i+1;
			}
			return n+1;
		}
		int firstMissingPositiveOld(int A[], int n){
			int i, ans;
			int64_t max, n_sum, a_sum;
			max = 0;
			a_sum = 0;
			for(i = 0; i < n; ++i){
				if(A[i] > max)
					max = A[i];
				if(A[i] > 0)
					a_sum += A[i];
			}
			n_sum = (max * (max+1)) / 2;
			ans = max + 1;
			max = n_sum - a_sum;
			while(a_sum != n_sum){
				max /= 2;
				ans = n_sum - a_sum;
				a_sum = 0;
				for(i = 0; i < n; ++i){
					if(A[i] > 0 && A[i] <= max)
						a_sum += A[i];
				}
				n_sum = (max * (max+1)) / 2;
			}
			return ans;
		}
};

int main(){
	int A[] = {3,4,-1,1};
	Solution sln;
	int ans = sln.firstMissingPositive(A, 4);
	cout<<ans<<endl;
	return 0;
}

