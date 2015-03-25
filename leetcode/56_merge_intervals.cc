/*
 * =====================================================================================
 *
 *       Filename:  56_merge_intervals.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2015 02:52:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<algorithm>
#include<iostream>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	static bool compare(Interval& t1, Interval& t2){
		return t1.start < t2.start;
	}
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> ans;
		if(intervals.size() == 0)
			return ans;
		Interval prev;
		std::sort(intervals.begin(), intervals.end(), compare);
		prev = intervals[0];
		for(auto& it : intervals){
			if(it.start <= prev.end){
				if(it.end > prev.end)
					prev.end = it.end;
			}else{
				ans.push_back(prev);
				prev = it;
			}
		}
		ans.push_back(prev);
		return ans;
    }
};

int main(){
	Solution sln;
	vector<Interval> intervals = {Interval(2,6), Interval(15,18), Interval(8,10), Interval(1,3)};
	vector<Interval> ans = sln.merge(intervals);
	for(auto& it : ans){
		cout<<it.start<<"-"<<it.end<<endl;
	}
	cout<<endl;
	return 0;

}
