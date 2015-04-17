/*
 * =====================================================================================
 *
 *       Filename:  121_best_time_buy_and_sell_stock.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2015 10:58:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<vector>
using namespace std;
class Solution{
	public:
		int maxProfit(vector<int>& prices){
			if(prices.size() == 0)
				return 0;
			unsigned int i;
			int min, ans;
			min = prices[0];
			ans = 0;
			for(i = 1; i != prices.size(); ++i){
				if(prices[i] < min){
					min = prices[i];
				}else{
					if(prices[i] - min > ans)
						ans = prices[i] - min;
				}
			}
			return ans;
		}
};
