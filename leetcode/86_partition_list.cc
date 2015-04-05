/*
 * =====================================================================================
 *
 *       Filename:  86_partition_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2015 09:28:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<limits.h>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
	public:
		ListNode* partition(ListNode* head, int x){
			if(x == INT_MIN )
				return head;
			ListNode* prev, * cur,* tail;
			ListNode new_head(x-1);
			new_head.next = head;
			prev = &new_head;
			cur = prev;
			tail = cur->next;
			while(tail != NULL && tail->val < x){
				prev = tail;
				cur = tail;
				tail = tail->next;
			}
			while(tail != NULL){
				if(tail->val < x){
					cur->next = tail->next;
					tail->next = prev->next;
					prev->next = tail;
					prev = prev->next;
					tail = cur->next;
				}
				else{
					cur = tail;
					tail = tail->next;
				}

			}
			return new_head.next;
		}
};
