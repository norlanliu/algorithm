/*
 * =====================================================================================
 *
 *       Filename:  33_search_rotated_sorted_array.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/2015 10:33:45 AM
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
		int binary_search(int* A, int left, int right, int target){
			int middle;
			while(left < right){
				middle = (left + right) / 2;
				if(A[middle] < target)
					left = middle + 1;
				else if(A[middle] > target)
					right = middle - 1;
				else
					return middle;
			}
			return A[left] == target ? left : -1;
		}
		int search(int A[], int n, int target){
            if(n == 0)
                return -1; 
            else if (n == 1)
                return A[0] == target ? 0 : -1; 
			int left, right, middle;
			left = 0;
			right = n - 1;

			while(left < right){
				middle = (left + right) / 2;
				if(A[middle] >= A[0])
					left = middle+1;
				else if(A[middle] <= A[n-1])
					right = middle;
			}
			if(target > A[0]){
				right = left;
				left = 1;
			}
			else if(target < A[0]){
				left = right;
				right = n - 1;
			}
			else
				return 0;

			return binary_search(A, left, right, target);
		}
		int binary_search_old(int* A, int left, int right, int target, bool asc){
			int middle;
			if(asc){
				while(left < right){
					middle = (left + right) / 2;
					if(A[middle] < target)
						left = middle + 1;
					else if(A[middle] > target)
						right = middle - 1;
					else
						return middle;
				}
			}
			else{
				while(left < right){
					middle = (left + right) / 2;
					if(A[middle] > target)
						left = middle + 1;
					else if(A[middle] < target)
						right = middle - 1;
					else
						return middle;
				}
			}
			return A[left] == target ? left : -1;
		}
		int searchOld(int A[], int n, int target){
			if(n == 0)
				return -1;
			else if (n == 1)
				return A[0] == target ? 0 : -1;
			else if(n == 2){
				if(A[0] == target)
					return 0;
				else if(A[1] == target)
					return 1;
				else 
					return -1;
			}
			int left, right, middle;
			left = 0;
			right = n;
			if(A[0] < A[1] && A[1] < A[n-1])
				return binary_search_old(A, 0, n-1, target, true);
			else if(A[n-1] < A[1] && A[1] < A[0])
				return binary_search_old(A, 0, n-1, target, false);
			bool asc = A[left] > A[right-1];
			if(asc){
				while(left != (right-1)){
					middle = (left + right) / 2;
					if(A[middle] >= A[0])
						left = middle;
					else if(A[middle] <= A[n-1])
						right = middle;
				}
				if(target > A[0]){
					right = left;
					left = 1;
				}
				else if(target < A[0]){
					left = right;
					right = n - 1;
				}
				else
					return 0;
			}
			else{
				while(left == (right-1)){
					middle = (left + right) / 2;
					if(A[middle] <= A[0])
						left = middle;
					else if(A[middle] >= A[n-1])
						right = middle;
				}
				if(target < A[0]){
					right = left;
					left = 1;
				}
				else if(target > A[0]){
					left = right;
					right = n - 1;
				}
				else
					return 0;
			}
			return binary_search_old(A, left, right, target, asc);
		}
};

int main()
{
	int size = 3;
	int A[] = {5 , 0, 1};
	int target = 1;
	Solution sln;
	int ans = sln.search(A, size, target);
	cout<<ans<<endl;
	return 0;
}
