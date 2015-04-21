/*
 * =====================================================================================
 *
 *       Filename:  122_best_time_buy_and_sell_stock2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/21/2015 08:47:46 AM
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
			prices.push_back(0);
			int i, current;
			int profit = 0;
			current = prices[0];
			for(i = 1; i != prices.size(); ++i){
				if(prices[i] <= prices[i-1]){
					if(prices[i-1] > current)
						profit += prices[i-1] - current;
					current = prices[i];
				}
			}
			return profit;
		}
};
