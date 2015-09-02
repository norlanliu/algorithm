/*
 * =====================================================================================
 *
 *       Filename:  234_panlindrome_linked_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/02/2015 09:32:09 AM
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* node) {
		int length = 0;
		bool odd = false;
		ListNode* head = node,* next_node,* tail;
		while(head != NULL){
			length += 1;
			head = head->next;
		}
		if(length == 1)
			return true;
		if(length & 1){
			odd = true;
		}
		head = NULL;
		next_node = node;
		length /= 2;
		for(int i = 0; i < length; ++i){
			tail = next_node->next;
			next_node->next = head;
			head = next_node;
			next_node = tail;
		}
		if(odd){
			next_node = next_node->next;
		}
		while(head != NULL){
			if(head->val != next_node->val){
				return false;
			}
			head = head->next;
			next_node = next_node->next;
		}
		return true;
    }
};
