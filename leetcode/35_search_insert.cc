/*
 * =====================================================================================
 *
 *       Filename:  35_search_insert.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/2015 08:23:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
	public:
		int searchInsert(int A[], int n, int target){
			int left, right, middle;
			left = 0;
			right = n;
			while(left < right){
				middle = (left + right) / 2;
				if(A[middle] < target){
					left = middle + 1;
				}
				else if(A[middle] > target)
					right = middle;
				else
					return middle;
			}
			return right;
		}
		int searchInsertOld(int A[], int n, int target){
			vector<int> data(A, A+n);
			return std::lower_bound(data.begin(), data.end(), target)-data.begin();
		}
};

int main()
{
	int A[] = {1};
	int target = 3;
	Solution sln;
	int ans = sln.searchInsert(A, 1, target);
	cout<<ans<<endl;
	return 0;
}
