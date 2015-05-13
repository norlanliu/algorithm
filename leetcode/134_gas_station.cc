/*
 * =====================================================================================
 *
 *       Filename:  134_gas_station.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2015 10:09:55 AM
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
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int i, j, size, lack;
		size = gas.size();
		lack = 0;
		for(i = 0 ; i != size; ++i){
			gas[i] -= cost[i];
			lack += gas[i];
		}
		if(lack < 0)
			return -1;
		for(i = 0; i != size; i = j+1){
			lack = 0;
			for(j = i; j != size && lack + gas[j] >= 0; ++j){
				lack += gas[j];
			}
			if(j == size)
				return i;
		}
		return -1;
    }
};
