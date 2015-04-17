/*
 * =====================================================================================
 *
 *       Filename:  105_construct_bt_from_pit.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2015 11:40:16 PM
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0)
			return NULL;
		unsigned int i, j;
		TreeNode* tmp;
		stack<TreeNode*> s;
		TreeNode* head = new TreeNode(preorder[0]);
		i = 1; j = 0;
		s.push(head);
		tmp = head;
		while(!s.empty() && i != preorder.size()){
			if(tmp->val == inorder[j]){
				s.pop();
				j++;
				while(!s.empty() && s.top()->val == inorder[j]){
					tmp = s.top();
					s.pop();
					j++;
				}
				tmp->right = new TreeNode(preorder[i]);
				tmp = tmp->right;
				s.push(tmp);
			}else{
				tmp->left = new TreeNode(preorder[i]);
				tmp = tmp->left;
				s.push(tmp);
			}
			i++;
		}
		return head;
    }
};
