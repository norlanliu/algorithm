/*
 * =====================================================================================
 *
 *       Filename:  123_best_time_buy_and_sell_stock3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/21/2015 04:52:19 PM
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
			int i, size, min, profit;
			size = prices.size();
			int left[size];
			int right[size];
			profit = 0;
			min = prices[0];
			for(i = 1; i != size; i++){
				if(prices[i] < min)
					min = prices[i];
				else if(profit < prices[i] - min)
					profit = prices[i] - min;
				left[i] = prices[i] - min;
			}
			min = prices[i-1];
			right[i-1] = 0;
			for(i -= 2; i > 1; --i){
				if(prices[i] > min)
					min = prices[i];
				else if(right[size-1] < min - prices[i])
					right[size-1] = min - prices[i];
				right[i] = right[size-1];
			}
			for(i = 1; i < size-2; ++i){
				if(left[i] + right[i+1] > profit)
					profit = left[i] + right[i+1];
			}
			return profit;
		}
};
