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
		vector<int> searchRange(int A[], int n, int target){
			int left, right, middle;
			vector<int> ans;
			left = 0;
			right = n;
			while(left < right){
				middle = (left + right) / 2;
				if(A[middle] < target){
					left = middle + 1;
				}
				else
					right = middle;
			}
			if(A[left] == target)
				ans.push_back(left);
			else
				return vector<int>(2,-1);

			right = n;
			while(left < right){
				middle = (left + right) / 2;
				if(A[middle] <= target){
					left = middle + 1;
				}
				else
					right = middle;
			}
			ans.push_back(left-1);
			return ans;
		}
};

int main()
{
	int A[] = {1,8,8,8,9};
	int target = 9;
	Solution sln;
	vector<int> ans = sln.searchRange(A, 5, target);
	for(auto it : ans)
		cout<<it<<endl;
	return 0;
}
