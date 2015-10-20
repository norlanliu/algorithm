/*
 * =====================================================================================
 *
 *       Filename:  223_rectangle_area.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2015 09:38:17 PM
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
#include<iostream>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int xlb = 0, xru = 0, ylb = 0, yru = 0;
		if(B < H && D > F && A < G && C > E){
			xlb = A < E ? E : A;
			xru = C < G ? C : G;
			ylb = B < F ? F : B;
			yru = D < H ? D : H;
		}
		return (D - B) * (C - A) + (H - F) * (G - E) - (xru - xlb) * (yru - ylb);
    }
};

int main() {
	Solution sln;
	cout<<sln.computeArea(-2, -2, 2, 2, -4, 3, -3, 4)<<endl;
	return 0;
}
