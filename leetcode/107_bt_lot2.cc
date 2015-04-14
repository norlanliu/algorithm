/*
 * =====================================================================================
 *
 *       Filename:  107_bt_lot2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/2015 11:27:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdio.h>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	vector<vector<int> > _ans;
	int preorder_level(TreeNode* node, int level){
		static int max_level = 1;
		if(level > max_level)
			max_level = level;
		if(node->left != NULL)
			preorder_level(node->left, level+1);
		if(node->right != NULL)
			preorder_level(node->right, level+1);
		return max_level;
	}
	void preorder(TreeNode* node, unsigned level){
		int size = _ans.size();
		_ans[size-level].push_back(node->val);
		if(node->left != NULL)
			preorder(node->left, level+1);
		if(node->right != NULL)
			preorder(node->right, level+1);
	}
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		if(root == NULL)
			return _ans;
		int max_level = preorder_level(root, 1);
		_ans.resize(max_level, vector<int>());
		preorder(root, 1);
		return _ans;
    }
};
