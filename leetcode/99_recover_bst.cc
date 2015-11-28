/*
 * =====================================================================================
 *
 *       Filename:  99_recover_bst.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/13/2015 02:37:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include <limits.h>
#include <stdio.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    // The reason for this initialization is to avoid null pointer exception in the first comparison when prevElement has not been initialized
    TreeNode* prevElement = NULL;
public:
    void recoverTree(TreeNode* root) {
        // In order traversal to find the two elements
        traverse(root);
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    void traverse(TreeNode* root) {
        if (root == NULL)
            return;
        traverse(root->left);
        // Start of "do some business", 
        // If first element has not been found, assign it to prevElement (refer to 6 in the example above)
        if (firstElement == NULL && prevElement != NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        // If first element is found, assign the second element to the root (refer to 2 in the example above)
        if (firstElement != NULL && prevElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;
        // End of "do some business"
        traverse(root->right);
	}
};

int main(){
	TreeNode* root  = new TreeNode(0);
	root->left = new TreeNode(1);
	printf("%d %d\n", root->val, root->left->val);
	Solution sln;
	sln.recoverTree(root);
	printf("%d %d\n", root->val, root->left->val);
	return 0;
}
