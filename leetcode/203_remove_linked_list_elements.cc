/*
 * =====================================================================================
 *
 *       Filename:  203_remove_linked_list_elements.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/17/2015 09:48:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode new_head(0);
		new_head.next = head;
		ListNode* old_ptr, * phead = &new_head;
		while(phead->next != NULL){
			if(phead->next->val == val){
				old_ptr = phead->next;
				phead->next = old_ptr->next;
				delete old_ptr;
			}else{
				phead = phead->next;
			}
		}
		return new_head.next;
    }
};
