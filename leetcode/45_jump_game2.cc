/*
 * =====================================================================================
 *
 *       Filename:  45_jump_game2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2015 09:47:15 AM
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
	int jump(int A[], int n){
		if(n <= 1)
			return 0;
		int i, steps, cur, next;
		steps = 1;
		cur = A[0];
		next = cur;
		for(i = 1; i < n && cur < n ; ++i){
			if(cur < i){
				cur = next;
				steps++;
			}
			if(A[i] + i > next){
				next = i + A[i];
			}
		}
		return steps;
	}
};

int main(){
	int A[] = {2,2,3,1,2,3,1,2,3};
	Solution sln;
	int ans = sln.jump(A, 9);
	cout<<ans<<endl;
	return 0;
}
