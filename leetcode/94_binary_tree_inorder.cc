/*
 * =====================================================================================
 *
 *       Filename:  94_binary_tree_inorder.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/22/2015 09:54:25 AM
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

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution{
	public:
		vector<int> inorderTraversal(TreeNode* root){
			if(root == NULL)
				return vector<int>();
			vector<int> ans;
			stack<TreeNode*> parents;
			parents.push(root);
			root = root->left;
			while(root != NULL || !parents.empty()){
				if(root == NULL){
					root = parents.top();
					ans.push_back(root->val);
					root = root->right;
					parents.pop();
				}else{
					parents.push(root);
					root = root->left;
				}
			}
			return ans;
		}

		vector<int> preorderTraversal(TreeNode* root){
			if(root == NULL)
				return vector<int>();
			vector<int> ans;
			stack<TreeNode*> parents;
			parents.push(root);
			ans.push_back(root->val);
			root = root->left;
			while(root != NULL || !parents.empty()){
				if(root == NULL){
					root = parents.top()->right;
					parents.pop();
				}else{
					ans.push_back(root->val);
					parents.push(root);
					root = root->left;
				}
			}
			return ans;
		}
};
