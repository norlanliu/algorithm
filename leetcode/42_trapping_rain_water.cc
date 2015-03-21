/*
 * =====================================================================================
 *
 *       Filename:  42_trapping_rain_water.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/19/2015 09:41:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stack>
#include<iostream>
using namespace std;
class Solution{
	public:
		int trap(int A[], int n){
			int i, j, prev, index, ans;
			stack<int> base;
			ans = 0;
			for(i = 1; i < n && A[i-1] <= A[i]; ++i){
			}
			j = i-1;
			base.push(j);
			for(; i < n; ++i){
				if(A[i] < A[j]){
					while(i < n-1 && A[i+1] == A[i])
						i++;
					if( A[i] != 0 )
						base.push(i);
					j = i;
				}
				else if(A[i] > A[j]){
					index = base.top();
					prev = 0;
					while(A[index] <= A[i]){
						ans += (i - index - 1) * (A[index] - prev);
						base.pop();
						prev = A[index];
						if(base.empty())
							break;
						index = base.top();
					}
					if(A[index] > A[i]){
						ans += (i - index - 1) * (A[i] - prev);
						base.push(index);
					}
					while(i < n-1 && A[i+1] == A[i])
						i++;
					base.push(i);
					j = i;
				}
			}
			return ans;
		}
};

int main()
{
	int A[] = {0,10,0,2,1,0,1,3,2,1,2,10,10};
	Solution sln;
	int ans = sln.trap(A, 13);
	cout<<ans<<endl;
	return 0;
}
