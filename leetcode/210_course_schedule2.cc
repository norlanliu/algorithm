/*
 * =====================================================================================
 *
 *       Filename:  210_course_schedule2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/26/2015 11:01:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ans;
        vector<vector<int>> matrix(numCourses, vector<int>());
		vector<int> degree(numCourses, 0);
		vector<int> starter;
		int i, pre;

		for(auto& p : prerequisites){
			degree[p.first] += 1;
			matrix[p.second].push_back(p.first);	
		}

		for(i = 0; i < numCourses; ++i){
			if(degree[i] == 0){
				starter.push_back(i);
			}
		}

		while(starter.size() != 0){
			pre = starter.back();
			starter.pop_back();
			for(auto i : matrix[pre]){
				degree[i]--;
				if(degree[i] == 0){
					starter.push_back(i);
				}
			}
			ans.push_back(pre);
		}
		return (int)ans.size() == numCourses ? ans : vector<int>();
    }
};
