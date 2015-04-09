/*
 * =====================================================================================
 *
 *       Filename:  88_merge_sorted_array.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2015 10:32:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		m = m-1;
		n = n-1;
		while(m != -1 && n != -1){
			if(A[m] < B[n]){
				A[m+n+1] = B[n--];
			}else{
				A[m+n+1] = A[m--];
			}
		}
		while(m != -1){
			A[m] = A[m--];
		}
		while(n != -1){
			A[n] = B[n--];
		}
	}
};

int main(){
	int A[9] = {-1,0,0,3,3,3};
	int B[3] = {1,2,2};
	Solution sln;
	sln.merge(A, 6, B, 3);
	for(int i = 0; i < 9; ++i)
		printf("%d\n", A[i]);
	return 0;
}
