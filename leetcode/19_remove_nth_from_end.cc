/*
 * =====================================================================================
 *
 *       Filename:  19_remove_nth_from_end.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/13/2015 08:59:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<iostream>
using namespace std;
struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x):val(x), next(NULL){}
};

class Solution{
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n){
			if(head == NULL)
				return NULL;
			int i, length;
			ListNode* tmp_head, * ans;
			tmp_head = head;
			length = 0;
			while(tmp_head != NULL)
			{
				length++;
				tmp_head = tmp_head->next;
			}
			tmp_head = head;
			length = length - n - 1;
			for(i = 0; i < length; ++i)
				tmp_head = tmp_head->next;
			if(length < 0)
			{
				ans = head->next;
				delete head;
				head = ans;
			}
			else
			{
				ans = tmp_head->next;
				tmp_head->next = ans->next;
				delete ans;
				ans = head;
			}
			return ans;
		}
};

int main()
{
	Solution sln;
	ListNode* head = new ListNode(0);
	ListNode* tmp = head;
	for(int i = 1; i < 6; ++i)
	{
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	tmp = sln.removeNthFromEnd(head, 6);
	head = tmp;
	while(tmp != NULL)
	{
		cout<<tmp->val<<endl;
		tmp = tmp->next;
	}
	while(head != NULL)
	{
		tmp = head->next;
		delete head;
		head = tmp;
	}
	return 0;
}
