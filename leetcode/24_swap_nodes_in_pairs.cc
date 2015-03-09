/*
 * =====================================================================================
 *
 *       Filename:  24_swap_nodes_in_pairs.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2015 02:24:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<iostream>

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
    ListNode *swapPairs(ListNode *head) {
		ListNode ret(0);
		ListNode* prev = &ret;
		ListNode* cur = head;
		prev->next = cur;
		while(cur && cur->next){
			prev->next = cur->next;
			cur->next = cur->next->next;
			prev->next->next = cur;

			cur = cur->next;
			prev = prev->next->next;
		}
		return ret.next;
	}
    ListNode *swapPairs_old(ListNode *head) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode* ret, *prev, *behind, *cur;
		prev = head;
		ret = head->next;
		cur = ret;
		head = head->next;
		while(head != NULL)
		{
			cur = head;
			behind = cur->next;
			cur->next = prev;
			cur = cur->next;
			prev = behind;
			if(behind != NULL)
				head = behind->next;
			else
				break;
			cur->next = head;
		}
		cur->next = prev;
		return ret;
    }
};

int main()
{
	Solution sln;
	ListNode* head;
	head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	ListNode* swap_list = sln.swapPairs(head);
	std::cout<<swap_list->val<<" "<<swap_list->next->val<<
		" "<<swap_list->next->next->val<<std::endl;
	return 0;
	
}
