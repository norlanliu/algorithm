/*
 * =====================================================================================
 *
 *       Filename:  82_remove_duplivates_from_list2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/03/2015 10:19:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL)
			return NULL;
		ListNode* prev, *cur, *tail, *old;
		bool is_duplicate;
		ListNode new_head(!(head->val));
		new_head.next = head;
		prev = &new_head;
		cur = head;
		tail = head->next;
		is_duplicate = false;
		while(tail != NULL){
			if(cur->val == tail->val){
				old = tail;
				tail = tail->next;
				delete old;
				is_duplicate = true;
			}
			else{
				if(is_duplicate){
					delete cur;
					cur = tail;
					tail = tail->next;
					is_duplicate = false;
				}
				else{
					prev->next = cur;
					prev = cur;
					cur = tail;
					tail = tail->next;
				}
			}
		}
		if(is_duplicate)
			prev->next = NULL;
		else
			prev->next = cur;
		return new_head.next;
    }
};
