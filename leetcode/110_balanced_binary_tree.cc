/*
 * =====================================================================================
 *
 *       Filename:  110_balanced_binary_tree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2015 07:32:28 PM
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
	int recursion(TreeNode* root, bool& ans){
		if(!ans)
			return 0;
		if(root == NULL)
			return -1;
		int left_height = recursion(root->left, ans) + 1;
		int right_height = recursion(root->right, ans) + 1;
		if(std::abs(left_height - right_height) > 1)
			ans = false;
		return std::max(left_height, right_height);
	}
	public:
		bool isBalanced(TreeNode* root){
			bool ans = true;
			recursion(root, ans);
			return ans;
		}
};
