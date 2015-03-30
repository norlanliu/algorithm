/*
 * =====================================================================================
 *
 *       Filename:  72_edit_distance.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2015 11:24:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>
using namespace std;

class Solution{
	int min(int a, int b, int c){
		if(a > b)
			a = b;
		if(a > c)
			a = c;
		return a;
	}
public:
	int minDistance(string word1, string word2){
		int i, j, m, n;
		int* distance;
		m = word1.size() + 1;
		n = word2.size() + 1;
		distance = (int*)malloc(sizeof(int) * m * n);

		for(j = 0; j < n; ++j){
			distance[j] = j;
		}
		for(i = 1; i < m; ++i){
			distance[i*n] = i;
		}

		for(i = 1; i < m; ++i){
			for(j = 1; j < n; ++j){
				distance[i*n+j] = min(
						distance[(i-1)*n+j-1] + (word1[i-1] != word2[j-1]),
						distance[(i-1)*n+j] + 1,
						distance[i*n+j-1] + 1);
			}
		}
		return distance[(i-1)*n+j-1];
	}
};

int main(){
	Solution sln;
	int distance = sln.minDistance("f", "c");
	cout<<distance<<endl;
	return 0;
}
