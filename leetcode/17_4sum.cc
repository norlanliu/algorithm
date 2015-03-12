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
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target){
			if(num.size() < 4)
				return vector<vector<int>>();
			unsigned int i, j;
			int k;
			vector<vector<int> > tuples;
			vector<int> tuple(4);
			unordered_map<int, vector<unsigned int> > map;
			size_t size = num.size() - 1;
			std::sort(num.begin(), num.end());
			
			for(i = 0; i < size; ++i)
			{
				while((i+2) <= size && num[i+2] == num[i])
					i++;
				for(j = i + 1; j < size; ++j)
				{
					if(num[j+1] != num[j])
					{
						k = num[i]+num[j];
						map[k].push_back(i);
					}
					if(num[i+1] == num[i])
						i++;
				}
				k = num[i]+num[j];
				map[k].push_back(i);
				while(num[i+1] == num[i])
					i++;
			}

			size -= 1;
			for(i = 0; i < size; ++i)
			{
				for(j = i + 1; j < size; ++j)
				{
					k = target - (num[i] + num[j]);
					vector<unsigned int>& vk = map[k];
					if(vk.size() > 0)
					{
						tuple[0] = num[i];
						tuple[1] = num[j];
						for(auto it : vk)
						{
							if(it > j)
							{
								tuple[2] = num[it];
								tuple[3] = k - tuple[2];
								tuples.push_back(tuple);
							}
						}
					}
					while(num[j+1] == num[j])
						j++;
				}
				while(num[i+1] == num[i])
					i++;
			}
			return tuples;
		}
		vector<vector<int> > fourSumTwoPointers(vector<int> &num, int target){
			if(num.size() < 4)
				return vector<vector<int>>();
			unsigned int i, j;
			int k, tmp, head, tail;
			vector<vector<int> > tuples;
			vector<int> tuple(4);
			size_t size = num.size() - 1;
			std::sort(num.begin(), num.end());

			for(i = 0; i < size; ++i)
			{
				for(j = i + 1; j < size; ++j)
				{
					k = num[i] + num[j];
					head = j + 1;
					tail = size;

					while(head < tail)
					{
						tmp = k + num[head] + num[tail];
						if(tmp < target)
							head++;
						else if(tmp > target)
							tail--;
						else
						{
							tuple[0] = num[i];
							tuple[1] = num[j];
							tuple[2] = num[head];
							tuple[3] = num[tail];
							tuples.push_back(tuple);
							while(head < tail && num[head] == tuple[2])
								head++;
							while(head < tail && num[tail] == tuple[3])
								tail--;
						}
					}

					while(num[j+1] == num[j])
						j++;
				}
				while(num[i+1] == num[i])
					i++;
			}
			return tuples;
		}
};

int main(){
	vector<int> num = {-1, 0, 1, 0, -2, 2};
	Solution sln;
	vector<vector<int> > ans = sln.fourSum(num, 0);
	for(auto out : ans)
	{
		for(auto inside : out)
		{
			cout << inside << " ";
		}
		cout<<endl;
	}
	return 0;
}
