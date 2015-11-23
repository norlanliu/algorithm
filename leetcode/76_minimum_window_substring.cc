/*
 * =====================================================================================
 *
 *       Filename:  76_minimum_window_substring.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2015 02:54:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<limits.h>
#include<string.h>
#include<string>
#include <unordered_map>
#include <queue>
#include<set>
#include<iostream>
using namespace std;

class Solution{
	struct KV{
		char key;
		int index;
		int value;
		KV(char k, int i, int v = -1):
			key(k), index(i),value(v){}
		bool operator<(const KV& rhs)const{
			return value < rhs.value;
		}
	};
	public:
		string minWindow_bak(string S, string T){
			unsigned int i, start, end, count;
			std::set<KV> keys;
			int mark[CHAR_MAX], mark2[CHAR_MAX];
			memset(mark, 0, sizeof(int) * CHAR_MAX);
			memset(mark2, 0, sizeof(int) * CHAR_MAX);
			for(auto c : T){
				mark[(int)c] += 1;
				mark2[(int)c] = 1;
			}
			start = 0;
			end = 0; 
			count = 0;
			for(i = 0; i < S.size(); ++i){
				if(mark[(int)S[i]] != 0){
					keys.insert(KV(S[i], mark[(int)S[i]], i)); 
					mark[(int)S[i]]--;
					count++;
					if(count == T.size()){
						end = i;
						break;
					}
				}
				else if(mark2[(int)S[i]] != 0){
					for(auto it = keys.begin(); it != keys.end(); ++it){
						if(it->key == S[i]){
							keys.insert(KV(it->key, it->index, i));
							keys.erase(it);
						}
					}
				}
			}
			if(keys.size() != 0)
				start = keys.begin()->value;
			for(i += 1; i < S.size(); ++i){
				if(mark2[(int)S[i]] != 0){
					for(auto it = keys.begin(); it != keys.end(); ++it){
						if(it->key == S[i]){
							keys.insert(KV(it->key, it->index, i));
							keys.erase(it);
							if((i - keys.begin()->value) < (end - start)){
								start = keys.begin()->value;
								end = i;
							}
							break;
						}
					}
				}
			}
			if(count == T.size())
				return S.substr(start, end-start+1);
			else
				return "";
		}
		string minWindow(string S, string T){
			if(T.size() == 0){
				return "";
			}
			int ssize = S.size();
			int i, tmp;
			int distance, start = 0, end = ssize-1, window_size = T.size();
			int front = 0, back = 0;
			vector<int> window_queue(ssize, 0);
			unordered_map<char, int> umap;
			for(auto c : T){
				if(umap.find(c) == umap.end()){
					umap[c] = 1;
				}else{
					umap[c] += 1;
				}
			}
			for(i = 0; i < ssize; ++i){
				if(umap.find(S[i]) != umap.end()){
					if(umap[S[i]] > 0){
						window_size--;
					}
					umap[S[i]] -= 1;
					window_queue[back] = i;
					back += 1;
					tmp = window_queue[front];
					while(umap[S[tmp]] < 0){
						umap[S[tmp]] += 1;
						front += 1;
						tmp = window_queue[front];
					}

					if(window_size == 0){
						distance = window_queue[back] - window_queue[front];
						if(distance < end-start){
							start = window_queue[front];
							end = window_queue[back];
						}
					}

				}
			}
			return window_size != 0 ? "" : S.substr(start, end-start+1);
		}
};

int main(){
	Solution sln;
	string S = "ADOECBODEBBANC";
	string T = "ABBC";
	string ans = sln.minWindow(S, T);
	cout<<ans<<endl;
	return 0;
}
