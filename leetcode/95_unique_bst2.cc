/*
 * =====================================================================================
 *
 *       Filename:  unique_bst2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 08:49:09 AM
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
#include<queue>
#include<string>
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int enumBST(int left, int right){
		if(left == right){
			return 1;
		}
		int i, ans;
		ans = 0;
		for( i = left; i <= right; ++i){
			if(left < i && i < right){
				ans += enumBST(left, i-1) * enumBST(i+1, right);
			}
			else if(i > left){
				ans += enumBST(left, i-1);
			}
			else if(i < right){
				ans += enumBST(i+1, right);
			}
		}
		return ans;
	}
public:
	/*
	 * DP : record the answer table
	 *
	 * NUM(i,j) represents the number of bst from i to j
	 *
	 * NUM(i,j) = NUM(i,j-1) + NUM(i+1,j) + (NUM(i,k-1)*NUM(k+1,j));(i+1<k<j-1)
	 */
    vector<TreeNode *> generateTrees(int n) {
		TreeNode* tmp;
		int i, j, k;
		vector<vector<vector<TreeNode*> > > mark(n+1);
		n += 1;
		for(i = 0; i < n; ++i){
			mark[i].resize(n);
			mark[i][i].push_back(new TreeNode(i));
		}
		for(i = n-2; i > 0; --i){
			for(j = i + 1; j < n; ++j){
				for(auto& it : mark[i][j-1]){
					tmp = new TreeNode(j);
					tmp->left = it;
					mark[i][j].push_back(tmp);
				}
				for(auto& it : mark[i+1][j]){
					tmp = new TreeNode(i);
					tmp->right = it;
					mark[i][j].push_back(tmp);
				}
				for(k = i + 1; k < j; ++k){
					for(auto& left: mark[i][k-1]){
						for(auto& right : mark[k+1][j]){
							tmp = new TreeNode(k);
							tmp->left = left;
							tmp->right = right;
							mark[i][j].push_back(tmp);
						}
					}
				}
			}
		}
		return mark[1][n-1];
    }
};

string PrintTree(TreeNode* root){
	if(root == NULL)
		return "";
	std::queue<TreeNode*> tree_queue;
	TreeNode* tmp;
	string str;
	tree_queue.push(root);
	while(tree_queue.size() != 0){
		tmp = tree_queue.front();
		tree_queue.pop();
		if(tmp != NULL){
			str.push_back(tmp->val + '0');
			str += ",";
			tree_queue.push(tmp->left);
			tree_queue.push(tmp->right);
		}
	}
	return str;
}

int main(){
	Solution sln;
	vector<TreeNode* > ans = sln.generateTrees(4);
	cout<<ans.size()<<endl;
	for(auto& it : ans){
		cout<<PrintTree(it)<<endl;
	}
	return 0;
}
