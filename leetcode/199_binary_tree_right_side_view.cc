/*
 * =====================================================================================
 *
 *       Filename:  199_binary_tree_right_side_view.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/26/2015 09:20:07 PM
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
/**
 * Definition for a binary tree node.
 */
#include <stdlib.h>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		if(root == NULL){
			return ans;
		}
        queue<TreeNode*> level;
		TreeNode* tmp;
		int up_size = 1, down_size = 0;
		level.push(root);
		while(!level.empty()){
			tmp = level.front();
			level.pop();
			if(tmp->left != NULL){
				level.push(tmp->left);
				down_size += 1;
			}
			if(tmp->right != NULL){
				level.push(tmp->right);
				down_size += 1;
			}
			up_size -= 1;
			if(up_size == 0){
				ans.push_back(tmp->val);
				up_size = down_size;
				down_size = 0;
			}
		}
		return ans;
    }
};
