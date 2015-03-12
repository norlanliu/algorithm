/*
 * =====================================================================================
 *
 *       Filename:  15_3sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/2015 11:03:41 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		int threeSumClosest(vector<int> &num, int target){
			if(num.size() < 3)
				return 0;
			unsigned int i, head, tail;
			int ans, tmp,  duplicate;
			size_t size = num.size() - 1;
			std::sort(num.begin(), num.end());

			ans = num[0] + num[1] + num[2];

			for(i = 0; i < size; ++i)
			{
				head = i + 1;
				tail = size;

				while(head < tail)
				{
					tmp = num[i] + num[head] + num[tail];
					if(tmp < target)
					{
						duplicate = num[head];
						while(head < tail && num[head] == duplicate)
							head++;
					}
					else if(tmp > target)
					{
						duplicate = num[tail];
						while(head < tail && num[tail] == duplicate)
							tail--;
					}
					else
					{
						return tmp;
					}
					if(std::abs(tmp - target) < std::abs(ans - target))
						ans = tmp;
				}

				while(num[i+1] == num[i])
					i++;
			}
			return ans;
		}
};

int main(){
	vector<int> num = {-1, 2, 1, 0, 0, 2, -1, -4};
	Solution sln;
	int ans = sln.threeSumClosest(num, 0);
	cout<<ans<<endl;
	return 0;
}
