/*
 * =====================================================================================
 *
 *       Filename:  23_merge_k_sorted_lists.cc
 *
 *    Description:  Merge k sorted lists using method: divide and conquer.
 *
 *        Version:  1.0
 *        Created:  03/13/2015 08:00:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
	public:
		ListNode* mergeKLists(vector<ListNode*> &lists){
			return merge(lists, 0, lists.size()-1);
		}
		ListNode* merge(vector<ListNode*> &lists, int front, int tail)
		{
			if(front > tail)
				return NULL;
			else if(front == tail)
				return lists[front];

			int middle = (front + tail) / 2;
			ListNode* left = merge(lists, front, middle);
			ListNode* right = merge(lists, middle+1, tail);

			ListNode head(0);
			ListNode *tmp = &head;
			while(left != NULL && right != NULL)
			{
				if(left->val < right->val)
				{
					tmp->next = left; 
					left = left->next;
				}
				else
				{
					tmp->next = right;
					right = right->next;
				}
				tmp = tmp->next;
			}
			while(left != NULL)
			{
				tmp->next = left; 
				left = left->next;
				tmp = tmp->next;
			}
			while(right != NULL)
			{
				tmp->next = right;
				right = right->next;
				tmp = tmp->next;
			}
			return head.next;
		}
};
