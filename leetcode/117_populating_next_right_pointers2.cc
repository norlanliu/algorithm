
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
        TreeLinkNode *p , *current;
		while(root != NULL){
			current = NULL;
			p = NULL;
			if(root->left != NULL){
				p = root->left;
				current = root->left;
			}
			if(root->right != NULL){
				if(p == NULL)
					p = root->right;
				if(current != NULL){
					current->next = root->right;
					current = current->next;
				}
				else
					current = root->right;
			}
			root = root->next;
			while(root != NULL){
				if(root->left != NULL){
					if(p == NULL)
						p = root->left;
					if(current == NULL)
						current = root->left;
					else{
						current->next = root->left;
						current = current->next;
					}
				}
				if(root->right != NULL){
					if(p == NULL)
						p = root->right;
					if(current == NULL)
						current = root->right;
					else{
						current->next = root->right;
						current = current->next;
					}
				}
				root = root->next;
			}
			root = p;
		}
    }
};
