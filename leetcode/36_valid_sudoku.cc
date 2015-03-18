/*
 * =====================================================================================
 *
 *       Filename:  36_valid_sudoku.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/17/2015 04:46:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>

#include<iostream>
#include<vector>
using namespace std;

class Solution{
	public:
		bool isValidSudoku(vector<vector<char> > &board){
			const int NUMBER = 10;
			const int size = 9;
			bool signal[NUMBER];
			int i, j,m,n;
			for(auto& row : board){
				memset(signal, 0, NUMBER);
				for(auto c : row){
					if(c != '.'){
						if(! signal[c-'0'])
							signal[c-'0'] = true;
						else
							return false;
					}
				}
			}
			for(j = 0; j < size; ++j){
				memset(signal, 0, NUMBER);
				for(i = 0; i < size; ++i){
					if(board[i][j] != '.'){
						if(! signal[board[i][j]-'0'])
							signal[board[i][j]-'0'] = true;
						else
							return false;
					}
				}
			}
			for(i = 0; i < size; i+=3){
				for(j = 0; j < size; j+=3){
					memset(signal, 0, NUMBER);
					for(m = 0; m < 3; ++m){
						for( n = 0; n < 3; ++n){
							if(board[i+m][j+n] != '.'){
								if(! signal[board[i+m][j+n]-'0'])
									signal[board[i+m][j+n]-'0'] = true;
								else
									return false;
							}
						}
					}
				}
			}
			return true;

		}
};
