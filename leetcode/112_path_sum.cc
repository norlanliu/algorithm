/*
 * =====================================================================================
 *
 *       Filename:  112_path_sum.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2015 07:59:15 PM
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
#include<utility>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	bool recursion(TreeNode* root, int sum, int target){
		if(root->left == NULL && root->right == NULL){
			if(sum + root->val == target)
				return true;
			return false;
		}
		bool ans = false;
		if(root->left != NULL)
			ans = recursion(root->left, sum + root->val, target);
		if(ans)
			return ans;
		if(root->right != NULL)
			ans = recursion(root->right, sum + root->val, target);
		return ans;
	}
public:
	bool hasPathSum_old(TreeNode* root, int sum){
		if(root == NULL)
			return false;
		return recursion(root, 0, sum);
	}
	bool hasPathSum(TreeNode* root, int sum){
		if(root == NULL)
			return false;
		int val;
		bool seen;
		TreeNode* node;
		stack<std::pair<TreeNode*, bool> > s;
		s.push(std::make_pair(root, false));
		while(!s.empty()){
			node = s.top().first;
			seen = s.top().second;
			val += node->val;
			if(seen){
				s.pop();
				val -= 2 * node->val;
			}else{
				std::pair<TreeNode*, bool>& tn = s.top();
				tn.second = true;
				if(root->right == NULL && root->left == NULL){
					if(val == sum)
						return true;
				}
				if(root->right != NULL)
					s.push(std::make_pair(root->right, false));
				if(root->left != NULL)
					s.push(std::make_pair(root->left, false));
			}
		}
		return false;
	}
};
