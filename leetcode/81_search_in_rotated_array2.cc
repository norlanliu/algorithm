/*
 * =====================================================================================
 *
 *       Filename:  81_search_in_rotated_array2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/03/2015 11:20:14 PM
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
	bool BinarySearch(int A[], int left, int right, int target){
		int i, count, step;
		count = right - left + 1;
		while(count != 0){
			i = left;
			step = count / 2;
			i += step;
			if(target > A[i]){
				left = ++i;
				count -= step+1;
			}else{
				count = step;
			}
		}
		if(left > right)
			return false;
		return A[left] == target;
	}
public:
	bool search(int A[], int n, int target) {
		if(n <= 0)
			return false;
		int i;
		for(i = 1; i != n && A[i] >= A[i-1]; ++i){
		}
		if(i == n){
			return BinarySearch(A, 0, n-1, target);
		}else if(target > A[n-1]){
			return BinarySearch(A, 0, i-1, target);
		}else{ 
			return BinarySearch(A, i, n-1, target);
		}
	}
};

int main(){
	int A[] = {1, 2};
	Solution sln;
	bool ans = sln.search(A, 2, 1);
	cout<<ans<<endl;
	return 0;
}
