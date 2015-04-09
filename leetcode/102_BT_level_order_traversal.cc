
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	struct LevelNode{
		TreeNode* node;
		int level;
		LevelNode(TreeNode* t, int l):node(t), level(l){}
	};
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if(root == NULL)
			return ans;
		unsigned node_count, cur_level_count, next_level_count=0;
		vector<int> tmp;
        queue<TreeNode*> tree_queue;
		TreeNode* cur;
		tree_queue.push(root);
		cur_level_count = 1;
		node_count = 0;
		while(tree_queue.size() != 0){
			cur = tree_queue.front();
			if(node_count != cur_level_count){
				tmp.push_back(cur->val);
				node_count++;
			}
			else{
				ans.push_back(tmp);
				tmp.clear();
				node_count = 1;
				tmp.push_back(cur->val);
				cur_level_count = next_level_count;
				next_level_count = 0;
			}
			if(cur->left != NULL){
				tree_queue.push(cur->left);
				next_level_count++; 
			}
			if(cur->right!= NULL){
				tree_queue.push(cur->right);
				next_level_count++; 
			}
			tree_queue.pop();
		}
		ans.push_back(tmp);
		return ans;
	}
    vector<vector<int> > levelOrder_old(TreeNode *root) {
		vector<vector<int> > ans;
		if(root == NULL)
			return ans;
		vector<int> tmp;
        queue<LevelNode> tree_queue;
		LevelNode cur(NULL, 0);
		int cur_level = 0;
		tree_queue.push(LevelNode(root, 0));
		while(tree_queue.size() != 0){
			cur = tree_queue.front();
			if(cur.level == cur_level){
				tmp.push_back(cur.node->val);
			}else{
				ans.push_back(tmp);
				cur_level = cur.level;
				tmp.clear();
				tmp.push_back(cur.node->val);
			}
			if(cur.node->left != NULL)
				tree_queue.push(LevelNode(cur.node->left, cur.level+1));
			if(cur.node->right!= NULL)
				tree_queue.push(LevelNode(cur.node->right, cur.level+1));
			tree_queue.pop();
		}
		ans.push_back(tmp);
		return ans;
    }
};
