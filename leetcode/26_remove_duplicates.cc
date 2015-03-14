/*
 * =====================================================================================
 *
 *       Filename:  26_remove_duplicates.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2015 10:22:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<iostream>

class Solution{
	public:
		int removeDuplicates(int A[], int n){
			if(n == 0)
				return 0;
			int i, j;
			for(i = 1, j = 0; i < n; ++i)
			{
				if(A[i-1] != A[i])
					A[j++] = A[i-1];
			}
			A[j++] = A[i-1];
			return j;
		}
};

int main()
{
	Solution sln;
	int length = 3;
	int A[length] = {1,1, 2};
	int ans = sln.removeDuplicates(A, length);
	std::cout<<ans<<std::endl;
	return 0;
}
