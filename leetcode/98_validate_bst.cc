/*
 * =====================================================================================
 *
 *       Filename:  98_validate_bst.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2015 11:20:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool CheckBST(TreeNode* root, long int& value,  bool left_right){
		if(root == NULL){
			if(left_right)
				value = LLONG_MIN;
			else
				value = LLONG_MAX;
			return true;
		}
		long int left, right;
		if((root->left != NULL && root->left->val >= root->val) ||
				(root->right != NULL && root->right->val <= root->val))
			return false;
		if(root->left == NULL && root->right == NULL){
			value = root->val;
			return true;
		}
		else{
			if(!CheckBST(root->left, left, true))
				return false;
			if(!CheckBST(root->right, right, false))
				return false;
		}
		if(!(left < root->val && root->val < right))
			return false;
		if(left_right){
			while(root->right != NULL)
				root = root->right;
		}else{
			while(root->left != NULL)
				root = root->left;
		}
		value = root->val;
		return true;
	}
public:
    bool isValidBST(TreeNode *root) {
		long int value;
		return CheckBST(root, value, true);
    }
};
