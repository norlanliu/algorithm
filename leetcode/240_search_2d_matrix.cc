/*
 * =====================================================================================
 *
 *       Filename:  240_search_2d_matrix.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/03/2015 04:04:53 PM
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
#include <iostream>
using namespace std;
class Solution {
	bool search2D(vector<vector<int>>& matrix, int startx, int starty,
			int endx, int endy, int target){
		int size_x = matrix[0].size(), size_y = matrix.size();
		if(startx < 0 || starty < 0 || endx >= size_x || endy >= size_y
				|| startx > endx || starty > endy){
			return false;
		}
		int middlex, middley;
		if(startx == endx){
			while(starty <= endy){
				middley = (starty + endy) / 2;
				if(matrix[middley][startx] > target){
					endy = middley - 1;
				}else if(matrix[middley][startx] < target){
					starty = middley + 1;
				}else{
					return true;
				}
			}
			return false;
		}
		if(starty == endy){
			while(startx <= endx){
				middlex = (startx + endx) / 2;
				if(matrix[starty][middlex] > target){
					endx = middlex - 1;
				}else if(matrix[starty][middlex] < target){
					startx = middlex + 1;
				}else{
					return true;
				}
			}
			return false;
		}
		int org_startx = startx, org_starty = starty;
		int org_endx = endx, org_endy = endy;
		int countx = endx - startx + 1;
		int county = endy - starty + 1;
		int stepx, stepy, retx, rety; 
		while(countx > 0 || county > 0){
			retx = endx;
			rety = endy;
			stepx = countx / 2;
			stepy = county / 2;
			retx -= stepx;
			rety -= stepy;
			if(matrix[rety][retx] > target){
				if(countx > 0){
					endx = retx >= 1 ? --retx : 0;
					countx -= stepx+1;
				}
				if(county > 0 ){
					endy = rety >= 1 ? --rety : 0;
					county -= stepy+1;
				}
			}else{
				countx = stepx;
				county = stepy;
			}
		}
		if(endx >= size_x || endy >= size_y){
			return false;
		}
		if(endx == 0 && endy == 0){
			if(matrix[0][0] > target){
				return false;
			}
		}
		if(matrix[endy][endx] == target){
			return true;
		}
		if(!search2D(matrix, endx+1, org_starty, org_endx, endy, target)){
			return search2D(matrix, org_startx, endy+1, endx, org_endy, target);
		}
		return true;
	}
	bool searchMN(vector<vector<int> >& matrix, int target){
		int size_y = matrix.size();
		if(size_y == 0){
			return false;
		}
		int size_x = matrix[0].size();

		int last;
		int i = size_x - 1, j = 0; 
		while(i > 0 && j < size_y){
			last = matrix[j][i];
			if(last < target){
				j++;
			}else if(last > target){
				i--;
			}else{
				return true;
			}
		}
		return false;
	}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size() == 0 || matrix[0].size() == 0){
			return false;
		}
		//return search2D(matrix, 0, 0, matrix[0].size()-1, matrix.size()-1, target);
		return searchMN(matrix, target);
    }
};

int main(){
	Solution sln;
	vector<vector<int> > matrix = {
		{4,7,10,10,12,17,18,22,23,24},
		{7,9,10,15,18,22,22,25,27,27},
		{8,10,11,17,23,23,23,30,34,36},
	};
	cout<<sln.searchMatrix(matrix, 2)<<endl;
	return 0;
}
