/*
 * =====================================================================================
 *
 *       Filename:  103.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/12/2015 10:52:40 PM
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if(root == NULL)
			return ans;
		vector<int> data;
		int level, prev_level_count, cur_level_count;
		TreeNode* tmp;
		stack<TreeNode*> s;
		stack<TreeNode*> odd_stack;
		prev_level_count = 1;
		cur_level_count = 0;
		level = 0;
		odd_stack.push(root);
		while(!s.empty() || !odd_stack.empty()){
			if(level & 1){
				tmp = s.top();
				s.pop();
				if(tmp->right != NULL){
					cur_level_count++;
					odd_stack.push(tmp->right);
				}
				if(tmp->left != NULL){
					cur_level_count++;
					odd_stack.push(tmp->left);
				}
			}else{
				tmp = odd_stack.top();
				odd_stack.pop();
				if(tmp->left != NULL){
					cur_level_count++;
					s.push(tmp->left);
				}
				if(tmp->right != NULL){
					cur_level_count++;
					s.push(tmp->right);
				}
			}
			prev_level_count--;
			data.push_back(tmp->val);
			if(!prev_level_count){
				ans.push_back(data);
				data.clear();
				level++;
				prev_level_count = cur_level_count;
				cur_level_count = 0;
			}
		}
		return ans;
    }
};
