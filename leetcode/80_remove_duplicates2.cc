/*
 * =====================================================================================
 *
 *       Filename:  80_remove_duplicates2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/03/2015 12:23:01 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

class Solution{
	public:
		int removeDuplicates(int A[], int n){
			if(n <= 0)
				return 0;
			int i, j, prev, count;
			j = 0;
			A[j++] = A[0];
			prev = A[0];
			count = 1;
			for(i = 1, j = 1; i < n; ++i){
				if(A[i] != prev)
					count = 0;
				if(2 - count != 0){
					A[j++] = A[i];
					count++;
				}
				prev = A[i];
			}
			return j;
		}
};
