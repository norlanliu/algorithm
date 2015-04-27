/*
 * =====================================================================================
 *
 *       Filename:  124_binary_tree_max_path_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2015 02:37:32 PM
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
	int max;
	int recursion(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
			if(root->val > max)
				max = root->val;
			return root->val;
		}
		int ans = INT_MIN;
		if(root->val > ans)
			ans = root->val;
		int left_max = 0, right_max = 0;
		if(root->left != NULL){
			left_max = recursion(root->left);
			if(left_max + root->val > ans)
				ans = left_max + root->val;
		}
		if(root->right != NULL){
			right_max = recursion(root->right);
			if(right_max + root->val > ans)
				ans = right_max + root->val;
		}
		if(ans > max)
			max = ans;
		if(left_max + root->val + right_max > max)
			max = left_max + root->val + right_max;  
		return ans;
	}
public:
    int maxPathSum(TreeNode *root) {
		if(root == NULL)
			return 0;
		max = INT_MIN;
		recursion(root);
		return max;
    }
};
