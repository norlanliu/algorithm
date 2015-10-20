/*
 * =====================================================================================
 *
 *       Filename:  173_binary_search_tree_iterator.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/20/2015 07:35:48 PM
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
#include <stdlib.h>
#include <stack>
using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
	stack<TreeNode*> _nodes;
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL){
			_nodes.push(root);
			root = root->left;
		}
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(_nodes.empty());
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* node = _nodes.top();
		int value = node->val;
		_nodes.pop();
		if(node->right != NULL){
			node = node->right;
			while(node != NULL){
				_nodes.push(node);
				node = node->left;
			}
		}
		return value;
    }
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
