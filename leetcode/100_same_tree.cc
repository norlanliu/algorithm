/*
 * =====================================================================================
 *
 *       Filename:  100_same_tree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/26/2015 10:27:18 AM
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
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
		if(p == NULL && q == NULL)
			return true;
		else if(p == NULL || q == NULL)
			return false;

		stack<TreeNode*> s;
		if(p->val != q->val){
			return false;
		}
		s.push(p);
		s.push(q);
		p = p->left;
		q = q->left;
		while(p != NULL || s.size() != 0){
			if(p == NULL && q == NULL){
				 q = s.top();
				 s.pop();
				 p = s.top();
				 s.pop();
				 p = p->right;
				 q = q->right;
			}else if(p != NULL && q != NULL){
				if(p->val != q->val){
					return false;
				}
				s.push(p);
				s.push(q);
				p = p->left;
				q = q->left;
			}else{
				return false;
			}
		}
		return true;
    }
};
int main(){
	TreeNode* p = new TreeNode(10);
	p->left = new TreeNode(5);
	p->right = new TreeNode(15);
	TreeNode* q = new TreeNode(10);
	q->left = new TreeNode(5);
	q->left->right = new TreeNode(15);
	Solution sln;
	bool ans = sln.isSameTree(p, q);
	cout<<ans<<endl;
	return 0;
}
