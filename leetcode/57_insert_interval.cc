/*
 * =====================================================================================
 *
 *       Filename:  57_insert_interval.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2015 06:31:24 PM
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
	static bool asc_cmp(Interval i, Interval j) { return (i.start < j.start);}
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ans;
		if(intervals.size() == 0){
			ans.push_back(newInterval);
			return ans;
		}
		std::vector<Interval>::iterator low;
		low = std::lower_bound(intervals.begin(), intervals.end(), newInterval, asc_cmp);
		if(low == intervals.end() ||( low->start > newInterval.start && low != intervals.begin())){
			low -= 1;
			if(newInterval.start <= low->end){
				newInterval.start = low->start;
				if(newInterval.end <= low->end){
					newInterval.end = low->end;
				}
			}
			else
				low += 1;
		}
		ans.insert(ans.begin(), intervals.begin(), low);
		while(low != intervals.end()){
			if(newInterval.end > low->end){
				low += 1;
			}else{
				if(newInterval.end >= low->start){
					newInterval.end = low->end;
					ans.push_back(newInterval);
					ans.insert(ans.begin()+ans.size(), low+1, intervals.end());
				}
				else{
					ans.push_back(newInterval);
					ans.insert(ans.begin()+ans.size(), low, intervals.end());
				}
				break;
			}
		}
		if(low == intervals.end())
			ans.push_back(newInterval);
		return ans;
    }
};
int main(){
	Solution sln;
	vector<Interval> intervals = {Interval(1,5)};
	vector<Interval> ans = sln.insert(intervals, Interval(-1,0));
	for(auto& it : ans){
		cout<<it.start<<"-"<<it.end<<endl;
	}
	cout<<endl;
	return 0;

}
