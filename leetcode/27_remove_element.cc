/*
 * =====================================================================================
 *
 *       Filename:  27_remove_element.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2015 10:51:39 AM
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
		int removeElement(int A[], int n, int elem){
			int i, j;
			for(i = 0, j = 0; i < n; ++i){
				if(A[i] != elem)
					A[j++] = A[i];
			}
			return j;
		}
};
