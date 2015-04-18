/*
 * =====================================================================================
 *
 *       Filename:  109_convert_sorted_list_to_bst.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2015 07:27:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<stdlib.h>

#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	TreeNode* convert(vector<int>& num, int start, int end){
		if(start > end)
			return NULL;
		if(start == end){
			return new TreeNode(num[start]);
		}
		int mid = (start + end) / 2;
		TreeNode* head = new TreeNode(num[mid]);
		if(start < mid)
			head->left = convert(num, start, mid-1);
		if(end > mid)
			head->right = convert(num, mid+1, end);
		return head;
	}
public:
    TreeNode *sortedListToBST(ListNode* head) {
		vector<int> num;
		while(head != NULL){
			num.push_back(head->val);
			head = head->next;
		}
		return convert(num, 0, num.size() - 1);
    }
};
