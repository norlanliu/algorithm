/*
 * =====================================================================================
 *
 *       Filename:  129_sum_root_to_leaf_numbers.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/30/2015 09:17:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	int ans;
	void backtracking(TreeNode* root, int value){
		value = value * 10 + root->val;
		if(root->left == NULL && root->right == NULL){
			ans += value;
			return;
		}
		if(root->left != NULL)
			backtracking(root->left, value);
		if(root->right != NULL)
			backtracking(root->right, value);
	}
public:
    int sumNumbers(TreeNode *root) {
		if(root == NULL)
			return 0;
        ans = 0;
		backtracking(root, 0);
		return ans;
    }
};
