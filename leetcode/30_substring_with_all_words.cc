/*
 * 
 * =====================================================================================
 *
 *       Filename:  30_substring_with_all_words.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/15/2015 08:34:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<string.h>

#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    double hash(double f, double code[], string &word) {
        double result = 0.;
        for (auto &c : word) result = result * f + code[c];
        return result;
    }
    vector<int> findSubstring(string S, vector<string> &L) {
        uniform_real_distribution<double> unif(0., 1.);
        default_random_engine seed;
        double code[128];
        for (auto &d : code) d = unif(seed);
        double f = unif(seed) / 5. + 0.8;
        double value = 0;
        for (auto &str : L) value += log(hash(f, code, str));
        int unit = 1e9;
        int key = (value-floor(value))*unit;
        int nS = S.size(), nL = L.size(), nW = L[0].size();
        double fn = pow(f, nW-1.);
        vector<int> result;
        if (nS < nW) return result;
        vector<double> values(nS-nW+1);
        string word(S.begin(), S.begin()+nW);
        values[0] = hash(f, code, word);
        for (int i=1; i<=nS-nW; ++i) values[i] = (values[i-1] - code[S[i-1]]*fn)*f + code[S[i+nW-1]];
        for (int i=0; i<nW; ++i) {
            int j0=i, j1=i, k=0;
            double sum = 0.;
            while(j1<=nS-nW) {
                sum += log(values[j1]);
                ++k;
                j1 += nW;
                if (k==nL) {
                    int key1 = (sum-floor(sum)) * unit;
                    if (key1==key) result.push_back(j0);
                    sum -= log(values[j0]);
                    --k;
                    j0 += nW;
                }
            }
        }
        return result;
    }
};

class Solution{
	public:
		vector<int> findSubstring(string S, vector<string> &L){
			if(L.size() == 0)
				return vector<int>();
			int i, j, length, size;
			string sub_str;
			unsigned int count;
			vector<int> ans;
			unordered_map<string, int> features, signals;
			length = L[0].length();
			size = S.size() - L.size() * length;
			bool marks[L.size()];
			memset(marks, 0, L.size());
			if(size < 0)
				return vector<int>();
			for(auto& it : L){
				features[it] = features[it] + 1;
			}
			for(i = 0; i <= size; ++i){
				if(!marks[i]){
					count = 0;
					j = i;
					sub_str = S.substr(j, length);
					signals.clear();
					while(features[sub_str] > signals[sub_str]){
						count++;
						if(count == L.size())
						{
							for(;j > i; j -= length)
								marks[j] = false;
							ans.push_back(i);
							break;
						}
						signals[sub_str] += 1;
						j += length;
						marks[j] = true;
						sub_str = S.substr(j, length);
					}
				}
			}
			return ans;
		}
};

int main(){
	string S = "abcaaaabaaabaaa";
	vector<string> L = {"aa", "aa", "ba"};
	Solution sln;
	vector<int> ans = sln.findSubstring(S,L);
	for(auto it : ans)
		cout<<it<<endl;
	return 0;
}
