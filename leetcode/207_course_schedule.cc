/*
 * =====================================================================================
 *
 *       Filename:  207_course_schedule.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/27/2015 07:51:11 PM
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
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if(numCourses == 0){
			return true;
		}
        vector<vector<int>> edges(numCourses, vector<int>());
		vector<int> counts(numCourses, 0);
		for(auto v : prerequisites){
			edges[v.second].push_back(v.first);
			counts[v.first] += 1;
		}
		int pass = 0;
		bool over = false;
		while(pass < numCourses){
			over = false;
			for(int i = 0; i < numCourses; ++i){
				if(counts[i] == 0){
					pass += 1;
					counts[i] = -1;
					for(auto node : edges[i]){
						counts[node]--;
					}
					over = true;
				}
			}
			if(!over){
				break;
			}
		}
		return pass == numCourses;
    }
};
int main(){
	Solution sln;
	vector<pair<int,int>> pre;
	pre.push_back(pair<int,int>(1,0));
	pre.push_back(pair<int,int>(2,0));
	cout<<sln.canFinish(3, pre)<<endl;
	return 0;
}
