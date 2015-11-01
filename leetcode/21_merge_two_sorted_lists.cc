/*
 * =====================================================================================
 *
 *       Filename:  21_merge_two_sorted_lists.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/01/2015 09:51:51 PM
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
#include <stdlib.h>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ans(0);
		ListNode* new_head = &ans;
		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				new_head->next = l1; 
				l1 = l1->next;
			}else{
				new_head->next = l2; 
				l2 = l2->next;
			}
			new_head = new_head->next;
		}
		while(l1 != NULL){
			new_head->next = l1; 
			l1 = l1->next;
			new_head = new_head->next;
		}
		while(l2 != NULL){
			new_head->next = l2; 
			l2 = l2->next;
			new_head = new_head->next;
		}
		return ans.next;
    }
};
