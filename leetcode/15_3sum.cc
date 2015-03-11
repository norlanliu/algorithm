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
#include<unordered_map>
using namespace std;

class Solution{
	public:
		vector<vector<int> > threeSum(vector<int> &num){
			if(num.size() < 3)
				return vector<vector<int>>();
			unsigned int i, j;
			int k;
			vector<vector<int> > tuples;
			vector<int> tuple(3);
			unordered_map<int, unsigned int> map();
			size_t size = num.size() - 1;
			std::sort(num.begin(), num.end());
			
			for(i = 0; i < size; ++i)
			{
				if(num[i+1] != num[i])
					map.insert(pair<int,int>(num[i], i));
			}
			map.insert(pair<int,int>(num[i], i));

			for(i = 0; i < size; ++i)
			{
				for(j = i + 1; j < size; ++j)
				{
					k = 0 - (num[i] + num[j]);
					if(map[k] > j)
					{
						tuple[0] = num[i];
						tuple[1] = num[j];
						tuple[2] = k;
						tuples.push_back(tuple);
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
	vector<int> num = {-1, 2, 0, 1, 0, 0, 0, 2, -1, -4};
	Solution sln;
	vector<vector<int> > ans = sln.threeSum(num);
	for(auto out : ans)
	{
		for(auto inside : out)
		{
			cout << inside << " "<<endl;
		}
		cout<<endl;
	}
	return 0;
}
