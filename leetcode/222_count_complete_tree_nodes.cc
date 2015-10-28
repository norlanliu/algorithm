/*
 * =====================================================================================
 *
 *       Filename:  222_count_complete_tree_nodes.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/2015 07:29:13 PM
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
#include<stdlib.h>
#include<math.h>
using namespace std;
/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int findRight(TreeNode* root, int cur_level, int height){
		while(cur_level != height){
			root = root->right;
			cur_level++;
		}
		if(root->right != NULL){
			return 2;
		}else if(root->left != NULL){
			return 1;
		}else{
			return 0;
		}
	}
public:
    int countNodes(TreeNode* root) {
		if(root == NULL){
			return 0;
		}
		if(root->left == NULL){
			return 1;
		}
        int height = 0, cur_level = 0, complete_nodes = 0, ans = 0;
		int start, step, ret;
		TreeNode* cur = root;
		while(cur->left != NULL){
			cur = cur->left;
			ans += pow(2, height);
			height++;
		}
		complete_nodes = pow(2, height);
		start = 0;
		cur = root;
		height -= 1;
		ret = findRight(cur, cur_level, height);
		if(ret == 0){
			step = complete_nodes / 2;
			cur_level = 1;
			while(cur_level <= height){
				ret = findRight(cur->left, cur_level, height);
				if(ret == 1){
					start += step - 1;
					break;
				}else if(ret == 0){
					cur = cur->left;
				}else {
					start += step;
					cur = cur->right;
				}
				step /= 2;
				cur_level += 1;
			}
		}else{
			start = complete_nodes - 2 + ret;
		}
		return ans+start;
    }
};
