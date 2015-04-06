/*
 * =====================================================================================
 *
 *       Filename:  85_maximal_rectangle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2015 02:41:00 PM
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

class Solution{
	struct point{
		int x;
		int y;
		point(int xv = 0, int yv = 0):x(xv), y(yv){}
	};
	public:
		int maximalRectangle(vector<vector<char> > &matrix){
			if(matrix.size() == 0 || matrix[0].size() == 0)
				return 0;
			int ans;
			unsigned int i, j;
			int x, y;
			int is_one;
			point tmp(1,1);
			vector<vector<point> > hv(matrix.size());
			vector<vector<point> > diagonal(matrix.size());
			for(i = 0; i != matrix.size(); ++i){
				hv[i].resize(matrix[0].size(), point());
				diagonal[i].resize(matrix[0].size(), point());
			}
			ans = 0;
			for(i = 0; i != matrix.size(); ++i){
				for(j = 0; j != matrix[0].size(); ++j){
					if(matrix[i][j] == '1'){
						if(ans == 0)
							ans = 1;
						hv[i][j] = tmp;
						diagonal[i][j] = tmp;
						is_one = 0;
						if(i != 0 && matrix[i-1][j] == '1'){
							hv[i][j].y += hv[i-1][j].y;
							is_one++;
							if(hv[i][j].y > ans)
								ans = hv[i][j].y;
						}
						if(j != 0 && matrix[i][j-1] == '1'){
							hv[i][j].x += hv[i][j-1].x;
							is_one++;
							if(hv[i][j].x > ans)
								ans = hv[i][j].x;
						}
						if(is_one == 2 && matrix[i-1][j-1] == '1'){
							x = std::min(hv[i-1][j-1].x, hv[i][j-1].x)+1;
							if((x << 1) > (diagonal[i][j].x*diagonal[i][j].y)){
								diagonal[i][j].x = x;
								diagonal[i][j].y = 2;
							}
							y = std::min(hv[i-1][j-1].y, hv[i-1][j].y) + 1;
							if((y << 1) > (diagonal[i][j].x*diagonal[i][j].y)){
								diagonal[i][j].x = 2;
								diagonal[i][j].y = y;
							}
							x = std::min(diagonal[i-1][j-1].x, hv[i-1][j-1].x);
							y = std::min(diagonal[i-1][j-1].y, hv[i-1][j-1].y);
							x = std::min(x, hv[i][j-1].x) + 1;
							y = std::min(y, hv[i-1][j].y) + 1;
							if((x*y) > diagonal[i][j].x*diagonal[i][j].y)
								diagonal[i][j] = point(x, y);
							if( diagonal[i][j].x*diagonal[i][j].y > ans)
								ans = diagonal[i][j].x*diagonal[i][j].y;
						}
					}
				}
			}
			return ans;
		}
};

int main(){
	Solution sln;
	vector<vector<char> > matrix = {
		{'0', '1', '1', '1'},
		{'1', '1', '1', '1'},
		{'1', '1', '1', '1'},
		{'0', '1', '1', '1'}};
	int ans = sln.maximalRectangle(matrix);
	cout<<ans<<endl;
	return 0;
	
}
