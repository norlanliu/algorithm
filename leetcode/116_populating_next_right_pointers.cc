
#include<stdlib.h>
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root == NULL)
			return ;
        TreeLinkNode *p, *current;
		while(root->left != NULL){
			p = root;
			current = root->left;
			current->next = root->right;
			root = root->next;
			while(root != NULL){
				current = current->next;
				current->next = root->left;
				current = current->next;
				current->next = root->right;
				root = root->next;
			}
			root = p->left;
		}
    }
};
