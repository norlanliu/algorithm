/*
 * =====================================================================================
 *
 *       Filename:  111_minimum_depth_of_bt.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2015 07:49:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		int minDepth(TreeNode* root){
			if(root == NULL)
				return 0;
			int left_height = minDepth(root->left);
			int right_height = minDepth(root->right);
			if(left_height == 0 || right_height == 0)
				return left_height + right_height + 1;
			else
				return std::min(left_height, right_height)+1;
		}
};
