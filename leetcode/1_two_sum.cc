/*
 * =====================================================================================
 *
 *       Filename:  1_two_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2015 08:32:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include <time.h>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sys/time.h>
using namespace std;

vector<int> TwoSum_1(vector<int> &numbers, int target)
{
	vector<int> ans;
	for(vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
			++it1)
	{
		for(vector<int>::iterator it2 = it1+1; it2 != numbers.end(); ++it2)
		{
			if((*it1 + *it2) == target)
			{
				ans.push_back(it1 - numbers.begin() + 1);
				ans.push_back(it2 - numbers.begin() + 1);
				return ans;
			}
		}
	}
	return ans;
}

vector<int> TwoSum_2(vector<int> &numbers, int target)
{
	int i, j;
	vector<int> ans;
	map<int, int> data;

	if((target % 2) == 0)
	{
		i = target / 2;
		j = 0;
		for(vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
			++it1)
		{
			if(*it1 == i)
			{
				if(j > 0)
				{
					ans.push_back(j);
					ans.push_back(it1 - numbers.begin() + 1);
					return ans;
				}
				else
					j = it1 - numbers.begin() + 1;
			}
		}
	}
	
	i = 1;
	for(vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
			++it1)
	{
		data.insert(pair<int,int>(*it1, i));
		i++;
	}
	for(map<int,int>::iterator it = data.begin(); it != data.end();
			++it)
	{
		if(data[target - it->first] > 0)
		{
			i = target - it->first;
			if(it->second < data[i])
			{
				ans.push_back(it->second);
				ans.push_back(data[i]);
			}
			else
			{
				ans.push_back(data[i]);
				ans.push_back(it->second);
			}
			return ans;
		}
	}
	return ans;
}

vector<int> TwoSum(vector<int> &numbers, int target)
{
	int i, j;
	vector<int> ans;
	unordered_map<int, int> data;

	if((target % 2) == 0)
	{
		i = target / 2;
		j = 0;
		for(vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
			++it1)
		{
			if(*it1 == i)
			{
				if(j > 0)
				{
					ans.push_back(j);
					ans.push_back(it1 - numbers.begin() + 1);
					return ans;
				}
				else
					j = it1 - numbers.begin() + 1;
			}
		}
	}
	
	i = 1;
	for(vector<int>::iterator it1 = numbers.begin(); it1 != numbers.end();
			++it1)
	{
		data.insert(pair<int,int>(*it1, i));
		i++;
	}
	for(unsigned j = 0; j < data.bucket_count(); ++j){
		for(auto it = data.begin(j); it != data.end(j); ++it)
		{
			auto got = data.find(target - it->first);
			if(got != data.end())
			{
				i = target - it->first;
				if(it->second < data[i])
				{
					ans.push_back(it->second);
					ans.push_back(data[i]);
				}
				else
				{
					ans.push_back(data[i]);
					ans.push_back(it->second);
				}
				return ans;
			}
		}
	}
	return ans;
}


int main()
{
	int target = 200;
	int array[] = {150,24,79,50,88,345,3};
	vector<int> numbers(array, array+sizeof(array)/sizeof(int));

	struct timeval start, end;
	gettimeofday(&start, NULL);
	vector<int> ans = TwoSum_2(numbers, target);
	gettimeofday(&end, NULL);
	cout<<"Time:"<<(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)<<endl;
	if(ans.size() == 2)
		cout<< ans[0] << ":" << array[ans[0]-1]<< " "
			<< ans[1] << ":" << array[ans[1]-1]<< endl;
	return 0;
}
