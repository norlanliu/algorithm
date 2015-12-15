/*
 * =====================================================================================
 *
 *       Filename:  212_word_search.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2015 10:35:49 AM
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
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
	struct node {
		int index;
		node* next[26];
		node(){index = -1; memset(next, 0, 26 * sizeof(node*));}
	};
	node* trie;
	vector<vector<bool>> state;
	set<string> ans;
	int xsize, ysize;
private:
	void buildTrie(vector<string>& words){
		trie = new node();
		node* tmp;
		int i, j, size;
		size = words.size();
		for(i = 0; i < size; i++){
			tmp = trie;
			for(auto c : words[i]){
				j = c - 'a';
				if(tmp->next[j] == NULL){
					tmp->next[j] = new node();
				}
				tmp = tmp->next[j];
			}
			tmp->index = i;
		}
	}
	void backtracking(vector<vector<char>>& board, vector<string>& words, int i, int j, node* cur) {
		if(cur->index >= 0){
			ans.insert(words[cur->index]);
		}
		node* tmp = NULL;
		if(i > 0 && state[i-1][j]){
			tmp = cur->next[board[i-1][j]-'a'];
			if(tmp != NULL){
				state[i-1][j] = false;
				backtracking(board, words, i-1, j, tmp);
				state[i-1][j] = true;
			}
		}
		if(j < ysize-1 && state[i][j+1]){
			tmp = cur->next[board[i][j+1]-'a'];
			if(tmp != NULL){
				state[i][j+1] = false;
				backtracking(board, words, i, j+1, tmp);
				state[i][j+1] = true;
			}
		}
		if(i < xsize - 1 && state[i+1][j]){
			tmp = cur->next[board[i+1][j]-'a'];
			if(tmp != NULL){
				state[i+1][j] = false;
				backtracking(board, words, i+1, j, tmp);
				state[i+1][j] = true;
			}
		}
		if(j > 0 && state[i][j-1]){
			tmp = cur->next[board[i][j-1]-'a'];
			if(tmp != NULL){
				state[i][j-1] = false;
				backtracking(board, words, i, j-1, tmp);
				state[i][j-1] = true;
			}
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		xsize = board.size();
		if(xsize == 0){
			return vector<string>();
		}
		ysize = board[0].size();
		state = vector<vector<bool>>(xsize, vector<bool>(ysize, true));

		buildTrie(words);

		int i, j, index;
		for(i = 0; i < xsize; i++){
			for(j = 0; j < ysize; j++){
				index = board[i][j] - 'a';
				if(trie->next[index] != NULL){
					state[i][j] = false;
					backtracking(board, words, i, j, trie->next[index]);
					state[i][j] = true;
				}
			}
		}
		vector<string> ret;
		for(auto str : ans){
			ret.push_back(str);
		}
        return ret;
    }
};

int main() {
	vector<vector<char>> board = {
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};
	vector<string> words = {"oath","pea","eat","rain", "teii"};
	Solution sln;
	vector<string> ans = sln.findWords(board, words);
	for(auto str : ans){
		cout<<str<<endl;
	}
	return 0;
}
