/*
 * =====================================================================================
 *
 *       Filename:  50_pow.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/20/2015 10:44:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<time.h>
#include<limits.h>
#include<iostream>
#include<stack>
using namespace std;

class Solution{
	public:
		double pow(double x, int n){
			if(n == 0)
				return 1;
			if(n < 0){
				n = -n;
				x = 1 / x;
			}

			return n&1 ? x * pow(x*x, n / 2) : pow(x*x, n / 2);
		}
		double pow_stack(double x, int n){
			if(n == 0)
				return 1;
			if(n < 0){
				n = -n;
				x = 1 / x;
			}
			int i;
			stack<int> base;
			double value, ans;
			for(i = 2; i <= n; i <<= 1){
			}
			i >>= 1;
			n -= i;
			base.push(i);
			i >>= 1;
			while(n != 0){
				if(n >= i){
					base.push(i);
					n -= i;
				}
				i >>= 1;
			}
			value = x;
			ans = 1;
			i = 1;
			while(base.size() != 0){
				if(i == base.top()){
					ans *= value;
					base.pop();
				}
				value *= value;
				i <<= 1;
			}
			return ans;
		}
};

int main(){
	Solution sln;
	double x = -0.001;
	int n = INT_MAX;
	clock_t start = clock();
	double ans  = sln.pow_stack(x, n);
	cout<<"Time : "<<(clock() - start)/CLOCKS_PER_SEC<<endl;
	cout<<ans<<endl;
	return 0;
}
