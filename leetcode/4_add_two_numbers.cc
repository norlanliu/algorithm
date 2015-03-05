/*
 * =====================================================================================
 *
 *       Filename:  4_add_two_numbers.cc
 *
 *    Description:  Add two numbers
 *
 *        Version:  1.0
 *        Created:  03/03/2015 08:51:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include <stdio.h>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
	public:
		ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
			if(l1 == NULL && l2 == NULL)
				return NULL;
			const int DECIMAL = 10;
			int carry, value;
			ListNode* ans, *tmp, *tmp1, *tmp2;
			//initialize the answer list
			carry = 0;
			if(l1 == NULL || l2 == NULL)
			{
				tmp = l1 == NULL ? l2 : l1;
				ans = new ListNode(tmp->val);
				tmp1 = tmp->next;
				tmp2 = NULL;
			}
			else
			{
				value = l1->val + l2->val;
				if(value >= DECIMAL)
				{
					value -= DECIMAL;
					carry = 1;
				}
				ans = new ListNode(value);
				tmp1 = l1->next;
				tmp2 = l2->next;
			}
			tmp = ans;
			//add the corresponding part 
			while(tmp1 != NULL && tmp2 != NULL)
			{
				value = tmp1->val + tmp2->val + carry;
				if(value >= DECIMAL)
				{
					value -= DECIMAL;
					carry = 1;
				}
				else
					carry = 0;
				tmp->next = new ListNode(value);
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
				tmp = tmp->next;
			}
			//add the remain part
			tmp1 = tmp1 == NULL ? tmp2 : tmp1;
			while(tmp1 != NULL)
			{
				value = tmp1->val + carry;
				if(value >= DECIMAL)
				{
					value -= DECIMAL;
					carry = 1;
				}
				else
					carry = 0;
				tmp->next = new ListNode(value);
				tmp1 = tmp1->next;
				tmp = tmp->next;
			}
			//add the last carry
			if(carry)
				tmp->next = new ListNode(carry);
			return ans;
		}
};
/*
 * test 1 + 9999999999
 */
void test1()
{
	Solution sln;
	ListNode* l1, *l2, *tmp1, *tmp2;
	l1 = new ListNode(1);
	l2 = new ListNode(9);
	tmp2 = l2;
	for(int i = 0; i < 10; ++i)
	{
		tmp2->next = new ListNode(9);
		tmp2 = tmp2->next;
	}
	tmp1 = l1;
	while(tmp1 != NULL)
	{
		fprintf(stdout, "%d->", tmp1->val);
		tmp1 = tmp1->next;
	}
	fprintf(stdout, "\n");
	tmp1 = l2;
	while(tmp1 != NULL)
	{
		fprintf(stdout, "%d->", tmp1->val);
		tmp1 = tmp1->next;
	}
	fprintf(stdout, "\n");
	ListNode* ans = sln.addTwoNumbers(l1, l2);
	tmp1 = ans;
	while(tmp1 != NULL)
	{
		fprintf(stdout, "%d->", tmp1->val);
		tmp2 = tmp1->next;
		delete tmp1;
		tmp1 = tmp2;
	}
	//free
	delete l1;
	while(l2 != NULL)
	{
		tmp1 = l2;
		delete l2;
		l2 = tmp1->next;
	}
	fprintf(stdout, "\n");
}

int main()
{
	test1();
	return 0;
}
