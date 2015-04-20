/*
 * =====================================================================================
 *
 *       Filename:  113_path_sum3.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2015 10:26:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<algorithm>
#include<stack>
#include<vector>
#include<utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	vector<vector<int> > ans;
	void recursion(TreeNode* root, int sum, int target, vector<int>& path){
		path.push_back(root->val);
		if(root->left == NULL && root->right == NULL){
			if(sum + root->val == target)
				ans.push_back(path);
		}else{
			if(root->left != NULL)
				recursion(root->left, sum + root->val, target, path);
			if(root->right != NULL)
				recursion(root->right, sum + root->val, target, path);
		}
		path.pop_back();
	}
public:
	vector<vector<int> > pathSum(TreeNode* root, int sum){
		if(root == NULL)
			return ans;
		vector<int> path;
		recursion(root, 0, sum, path);
		return ans;
	}
	vector<vector<int> > pathSum_stack(TreeNode* root, int sum){
		vector<vector<int> > ans;
		if(root == NULL)
			return ans;
		int val;
		bool seen;
		TreeNode* node;
		vector<int> path;
		stack<std::pair<TreeNode*, bool> > s;
		s.push(std::make_pair(root, false));
		while(!s.empty()){
			node = s.top().first;
			seen = s.top().second;
			if(seen){
				s.pop();
				val -= node->val;
				path.pop_back();
			}else{
				val += node->val;
				path.push_back(node->val);
				std::pair<TreeNode*, bool>& tn = s.top();
				tn.second = true;
				if(root->right == NULL && root->left == NULL){
					if(val == sum)
						ans.push_back(path);
				}
				else{
					if(root->right != NULL)
						s.push(std::make_pair(root->right, false));
					if(root->left != NULL)
						s.push(std::make_pair(root->left, false));
				}
			}
		}
		return ans;
	}
};
