/*
 * =====================================================================================
 *
 *       Filename:  70_climbing_stairs.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/29/2015 06:49:47 PM
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

class Solution {
public:
    int climbStairs(int n) {
        int i, ans, prev, next;
		ans = 1;
		prev = 1;
		next = 1;
		for(i = 2; i <= n; ++i){
			ans = prev + next;
			prev = next;
			next = ans;
        }
		return ans;
    }
};

int main(){
	Solution sln;
	for(int i = 0; i < 10; ++i){
		int ans = sln.climbStairs(i);
		cout<<ans<<endl;
	}
	return 0;
}
