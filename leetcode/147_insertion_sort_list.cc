/*
 * =====================================================================================
 *
 *       Filename:  147_insertion_sort_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/2015 06:58:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		if(head == NULL)
			return NULL;
		int value;
		ListNode* tmp, *cur, *prev, *tail;
		prev = head;
		cur = head->next;
		head->next = NULL;
		while(cur != NULL){
			tail = cur->next;
			value = cur->val;
			tmp = cur;
			cur->next = prev;
			while(tmp->next != NULL && value > tmp->next->val)
				tmp = tmp->next;
			if(cur != tmp){
				cur->next = tmp->next;
				tmp->next = cur;
			}else{
				prev = cur;
			}
			cur = tail;
		}
		return prev;
	}
    ListNode* insertionSortList_old(ListNode* head) {
		int value;
		ListNode new_head(0);
		new_head.next = head;
		ListNode* tmp, *cur, *prev;
		tmp = &new_head;
		prev = &new_head;
		while(tmp != NULL && tmp->next != NULL && tmp->next->next != NULL){
			prev = tmp;
			tmp = tmp->next;
		}
		cur = tmp;
		while(prev != cur){
			tmp = cur;
			value = tmp->val;
			while(tmp->next != NULL && value > tmp->next->val)
				tmp = tmp->next;
			if(cur != tmp){
				prev->next = cur->next;
				cur->next = tmp->next;
				tmp->next = cur;
			}
			cur = prev;
			prev = &new_head;
			tmp = prev;
			while(tmp != cur){
				prev = tmp;
				tmp = tmp->next;
			}
		}
		return new_head.next;
    }
};
