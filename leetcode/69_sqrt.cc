/*
 * =====================================================================================
 *
 *       Filename:  69_sqrt.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 09:29:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<limits.h>
#include<iostream>
using namespace std;

class Solution{
	public:
		int sqrt(int x){
			if(x <= 0)
				return 0;
			int high, low, middle, tmp;
			high = 16;
			low = 0;
			while(high != (low+1)) {
				middle = (low + high) >> 1;
				if(x >> middle > (1 << middle)){
					low = middle;
				}else if((x >> middle) < (1 << middle)){
					high = middle;
				}else{
					return 1<<middle;
				}
			}
			high = 1 << high;
			low = 1 << low;
			while(high != low+1){
				middle = (high + low) / 2;
				tmp = x / middle;
				if(tmp > middle){
					low = middle;
				}else if(tmp <  middle ){
					high = middle;
				}else
					return middle;
			}
			return low;
		}
};

int main(){
	Solution sln;
	int ans = sln.sqrt(INT_MAX);
	cout<<"sqrt "<<INT_MAX<<"="<<ans<<endl;
	return 0;
}
