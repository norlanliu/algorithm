/*
 * =====================================================================================
 *
 *       Filename:  144_binary_tree_preorder_traversal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2015 10:58:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<stdlib.h>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(root == NULL)
			return ans;
        stack<TreeNode*> s;
		TreeNode* node;
		s.push(root);
		while(!s.empty()){
			node = s.top();
			s.pop();
			ans.push_back(node->val);
			if(node->right != NULL)
				s.push(node->right);
			if(node->left != NULL)
				s.push(node->left);
		}
		return ans;
    }
};
