/*
 * =====================================================================================
 *
 *       Filename:  208_trie.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/06/2015 03:26:55 PM
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
#include <iostream>
#include <string>
using namespace std;


class TrieNode {
	static const int ALPHA_COUNT = 26;
public:
    // Initialize your data structure here.
	bool is_word;
	TrieNode* children[ALPHA_COUNT];
    TrieNode() {
		is_word = false;
		memset(children, 0, ALPHA_COUNT * sizeof(int));
    }
};
class Trie {
	TrieNode* FindLastNode(string word){
		int i;
		TrieNode* cur = root;
        for(auto iter = word.begin(); iter != word.end(); ++iter){
			i = *iter - 'a';
			if(cur->children[i] != NULL){
				cur = cur->children[i];
			}else{
				return NULL;
			}
		}
		return cur;
	}
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
		if(word.size() == 0){
			return;
		}
		int i;
		TrieNode* cur;
		cur = root;
        for(auto iter = word.begin(); iter != word.end(); ++iter){
			i = *iter - 'a';
			if(cur->children[i] == NULL){
				cur->children[i] = new TrieNode();;
			}
			cur = cur->children[i];
		}
		cur->is_word = true;
    }
    // Returns if the word is in the trie.
    bool search(string word) {
		TrieNode* cur = FindLastNode(word);
		return cur == NULL ? false : cur->is_word;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
		TrieNode* cur = FindLastNode(prefix);
		return cur != NULL;
    }
private:
    TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main() {
	Trie trie;
	trie.insert("nemathelmintha");
	trie.insert("nemathelminth");
	trie.insert("entracte");
	cout<<trie.startsWith("nema")<<endl;
	cout<<trie.search("emathelmintha")<<endl;
	return 0;
}
