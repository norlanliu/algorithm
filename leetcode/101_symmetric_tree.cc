
#include<stdlib.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool recursive(TreeNode* left_part, TreeNode* right_part){
        if((left_part != NULL && right_part != NULL)){
            if(left_part->val != right_part->val)
				return false;
			else{
				if(recursive(left_part->left, right_part->right)){
					if(recursive(left_part->right, right_part->left))
						return true;
				}
			}
		}
        else if(left_part == NULL && right_part == NULL)
            return true;
		return false;
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
			return true;
		return recursive(root->left, root->right);
    }
};
