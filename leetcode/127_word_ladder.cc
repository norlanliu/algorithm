/*
 * =====================================================================================
 *
 *       Filename:  127_word_ladder.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2015 11:25:07 AM
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
#include <limits.h>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>

using namespace std;
class Solution {
	unordered_map<string, int> _distance;
	string _end_word;
	int _word_size;

	int distance(string& first, string& second){
		int diff = _word_size;
		for(int i = 0; i < _word_size; ++i){
			if(first[i] == second[i]){
				diff--;
			}
		}
		return diff;
	}

	int backtracking(string beginWord, unordered_map<string, bool>& words){
		int dist;
		if(distance(beginWord, _end_word) == 1){
			return 2;
		}
		if(words.size() == 0){
			return INT_MAX;
		}
		if(_distance[beginWord] != INT_MAX){
			return _distance[beginWord];
		}
		int min_dist = INT_MAX;
		string word;

		for(auto it = words.begin(); it != words.end(); ++it){
			if(!(it->second)){
				word = it->first;
				if(distance(beginWord, word) == 1){
					words[word] = true;
					dist = backtracking(word, words);
					if(dist != INT_MAX){
						if(dist + 1 < min_dist){
							min_dist = dist + 1;
						}
					}
					words[word] = false;
				}
			}
		}
		if(min_dist == INT_MAX){
			return INT_MAX;
		}else{
			_distance[beginWord] = min_dist;
			return min_dist;
		}
	}
public:
    int ladderLength_bak(string beginWord, string endWord, unordered_set<string>& wordList) {
		unordered_map<string, bool> words;
        _end_word = endWord;
		_word_size = beginWord.size();
		_distance[beginWord] = INT_MAX;
		for(auto str : wordList){
			_distance[str] = INT_MAX;
			words[str] = false;
		}
		int dist = backtracking(beginWord, words);
		if(dist != INT_MAX){
			return dist;
		}else{
			return 0;
		}
    }

	struct node {
		int length;
		string str;
	};
	void addNextWords(string word, int length, unordered_set<string>& wordList, queue<node>& toVisit) {
        wordList.erase(word);
        for (int p = 0; p < (int)word.length(); p++) {
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordList.find(word) != wordList.end()) {
                    toVisit.push(node{length,word});
                    wordList.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		_word_size = beginWord.size();
		int cur_length = distance(beginWord, endWord);
		if(cur_length <= 1){
			return cur_length;
		}
		queue<node> qu;
		node tmp;
		int min_length = INT_MAX;
		addNextWords(beginWord, 1, wordList, qu); 
		while(qu.size() != 0){
			tmp = qu.front();
			qu.pop();
			cur_length = tmp.length;
			if(cur_length >= min_length){
				continue;
			}
			if(distance(tmp.str, endWord) == 1){
				if(cur_length < min_length){
					min_length = cur_length;
				}
				continue;
			}
			addNextWords(tmp.str, tmp.length+1, wordList, qu); 
		}
		return 2+min_length;
	}
};

int main() {
	unordered_set<string> wordList = {"hot", "dot", "dog", "hig", "lot", "log", "hog"};

	Solution sln;
	int n = sln.ladderLength("hit", "cog", wordList);
	cout<<n<<endl;
	return 0;
}
