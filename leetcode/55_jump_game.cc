/*
 * =====================================================================================
 *
 *       Filename:  55_jump_game.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2015 10:46:21 AM
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
		bool canJump(int A[], int n){
			if(n < 2)
				return true;
			int i, max;
			max = 0;
			n -= 1;
			for(i = 0; i <= n; ++i){
				if(A[i] == 0){
					if(max <= i)
						return false;
				}else{
					if(A[i] + i > max)
						max = A[i] + i;
					if(max >= n)
						return true;
				}
			}
			return true;
		}
};
