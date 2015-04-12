/*
 * =====================================================================================
 *
 *       Filename:  104_max_depth_binary_tree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 10:52:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>

#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	void dfs(TreeNode* root, int level, int& ans){
		if(root == NULL)
			return;
		if(level > ans)
			ans = level;
		dfs(root->left, level+1, ans);
		dfs(root->right, level+1, ans);
	}
public:
    int maxDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
		int i, level, prev_level_count, cur_level_count;
		TreeNode* tmp;
		queue<TreeNode*> q;
		q.push(root);
		prev_level_count = 1;
		cur_level_count = 0;
		level = 0;
		i = 0;
		while(!q.empty()){
			tmp = q.front();
			q.pop();
			i++;
			if(tmp->left != NULL){
				cur_level_count++;
				q.push(tmp->left);
			}
			if(tmp->right != NULL){
				cur_level_count++;
				q.push(tmp->right);
			}
			if(i == prev_level_count){
				level++;
				i = 0;
				prev_level_count = cur_level_count;
				cur_level_count = 0;
			}
		}
		return level;
    }
};
