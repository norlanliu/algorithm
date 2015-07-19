/*
 * =====================================================================================
 *
 *       Filename:  160_intersection_two_linked_lists.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/19/2015 07:56:24 PM
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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int la = 0, lb = 0;
		ListNode* new_a = headA;
		ListNode* new_b = headB;
		while(new_a != NULL){
			la++;
			new_a = new_a->next;
		}
		while(new_b != NULL){
			lb++;
			new_b = new_b->next;
		}
		new_a = headA;
		new_b = headB;
		if(la < lb){
			while(la != lb){
				new_b = new_b->next;
				lb--;
			}
		}else if(la > lb) {
			while(la != lb){
				new_a = new_a->next;
				la--;
			}
		}
		while(new_a != NULL){
			if(new_a == new_b){
				return new_a;
			}
			new_a = new_a->next;
			new_b = new_b->next;
		}
		return NULL;
    }
};
