/*
 * =====================================================================================
 *
 *       Filename:  75_sort_colors.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2015 10:22:10 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string.h>
#include<algorithm>

class Solution{
	public:
		void sortColors(int A[], int n){
			int i, red, white;
			red = 0; white = 0;
			for(i = 0; i < n; ++i){
				switch(A[i]){
					case 0 :
						red++;
						break;
					case 1:
						white++;
						break;
				}
			}
			memset(A, 0, red*sizeof(int));
			std::fill_n(A+red, white, 1);
			std::fill_n(A+red+white, n-red-white, 2);
		}
};

int main(){
	int A[] = {2};
	Solution sln;
	sln.sortColors(A, 1);
	return 0;
}
