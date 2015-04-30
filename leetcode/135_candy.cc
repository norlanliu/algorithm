/*
 * =====================================================================================
 *
 *       Filename:  candy.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/30/2015 10:23:02 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
	enum{
		DES,
		ASC
	};
public:
    int candy(vector<int>& ratings) {
		if(ratings.size() == 1)
			return 1;
		int i, j, order, prev, ans;
		ans = 0;
		prev  = 1;
		if(ratings[1] < ratings[0]){
			j = 0;
			order = DES;
		}else{
			ans += 1;
			order = ASC;
		}
		for(i = 1; i != ratings.size(); ++i){
			if(ratings[i] > ratings[i-1]){
				if(order == DES){
				    j = i - j;
					ans += (j - 1) * j / 2;
					ans += std::max(j, prev);
					order = ASC;
					prev = 1;
				}
				prev += 1;
				ans += prev;
			}else if(ratings[i] < ratings[i-1]){
				if(order != DES){
					j = i-1;
					ans -= prev;
					order = DES;
				}
			}else{
				if(order == DES){
				    j = i - j;
					ans += (j - 1) * j / 2;
					ans += std::max(j, prev);
					order = ASC;
				}
				prev = 1;
				ans += 1;
			}
		}
		if(order == DES){
		    j = i - j;
			ans += (j - 1) * j / 2;
			ans += std::max(j, prev);
		}
		return ans;
    }
};
int main(){
	vector<int> num = {1,2,4,4,3};
	Solution sln;
	cout<<sln.candy(num)<<endl;
	return 0;
}
