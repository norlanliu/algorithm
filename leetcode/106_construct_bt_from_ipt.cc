/*
 * =====================================================================================
 *
 *       Filename:  106_construct_bt_from_ipt.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/17/2015 07:54:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<stdlib.h>

#include<stack>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.size() == 0 || postorder.size() == 0){
			return NULL;
		}
		int i, j;
		stack<TreeNode*> s;
		i = postorder.size() - 1;
		j = inorder.size() - 1;
		TreeNode* tmp;
		TreeNode* head = new TreeNode(postorder[i]);
		s.push(head);
		tmp = head;
		i--;
		while(!s.empty() && i != -1){
			if(tmp->val == inorder[j]){
				s.pop();
				j--;
				while(!s.empty() && s.top()->val == inorder[j]){
					j--;
					tmp = s.top();
					s.pop();
				}
				tmp->left = new TreeNode(postorder[i]);
				tmp = tmp->left;
			}else{
				tmp->right = new TreeNode(postorder[i]);
				tmp = tmp->right;
			}
			s.push(tmp);
			i--;
		}
		return head;
	}
};
