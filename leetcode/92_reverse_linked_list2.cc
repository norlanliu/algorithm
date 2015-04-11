/*
 * =====================================================================================
 *
 *       Filename:  92_reverse_linked_list2.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/11/2015 11:25:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		int i;
        ListNode* prev, *cur, *tail;
		ListNode new_head(0);
		new_head.next = head;
		prev = &new_head;
		for(i = 1; i < m; ++i){
			prev = prev->next;
		}
		cur = prev->next;
		while(i != n){
			tail = cur->next;
			cur->next = tail->next;
			tail->next = prev->next;
			prev->next = tail;
			i++;
		}
		return new_head.next;
    }
};
