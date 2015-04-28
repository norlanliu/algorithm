/*
 * =====================================================================================
 *
 *       Filename:  145_binary_tree_postorder_traversal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2015 11:05:30 PM
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
#include<utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	struct KV{
		TreeNode* first;
		bool second;
		KV(TreeNode* f, bool s):first(f), second(s){}
	};
public:
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if(root == NULL)
			return ans;
		bool type;
		stack<KV> s;
		s.push(KV(root, false));
		while(!s.empty()){
			root = s.top().first;
			type = s.top().second;
			s.pop();
			if(type){
				ans.push_back(root->val);
			}
			s.push(KV(root, true));
			if(root->right != NULL)
				s.push(KV(root->right, false));
			if(root->left != NULL)
				s.push(KV(root->left, false));
		}

	}
};
