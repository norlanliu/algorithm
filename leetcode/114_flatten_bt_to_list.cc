/*
 * =====================================================================================
 *
 *       Filename:  114_flatten_bt_to_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/24/2015 08:51:31 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
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
    void flatten(TreeNode *root) {
		if(root == NULL)
			return;
		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty()){
			root = s.top();
			s.pop();
			if(root->right != NULL)
				s.push(root->right);
			if(root->left != NULL)
				s.push(root->left);
			if(!s.empty()){
				root->right = s.top();
				root->left = NULL;
			}
		}
    }
};

int main(){
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	Solution sln;
	sln.flatten(root);
	while(root != NULL){
		cout<<root->val<<endl;
		root =root->right;
	}
	return 0;
}
