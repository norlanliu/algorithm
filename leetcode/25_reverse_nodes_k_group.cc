/* =====================================================================================
 *
 *       Filename:  25_reverse_nodes_k_group.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/14/2015 09:11:16 AM
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		int i, j, length;
		ListNode* ans, *front, *back, *cur, *next_head;
		cur = head;
		length = 0;
		while(cur != NULL)
		{
			length++;
			if(length == k)
				ans = cur;
			cur = cur->next;
		}
		if(k <= 1 || length < k)
			return head;
		front = head;
		cur = head->next;

		length /= k;
		for(i = 0; i < length; ++i)
		{
			for(j = 1; j < k; ++j)
			{
				back = cur->next;
				cur->next = front;
				front = cur;
				cur = back;
			}
			//connect the two part reversed.
			if(i > 0)
			{
				head->next = front;
				head = next_head;
			}
			next_head = cur;
			//forward
			if(cur != NULL)
			{
				front = cur;
				cur = cur->next;
			}
			else
				front = NULL;
		}
		//deal with the last connection
		head->next = front;
		return ans;
    }
};

int main()
{
	Solution sln;
	int i;
	ListNode* head = new ListNode(1);
	ListNode* tmp = head;
	for(i = 2; i < 8; ++i)
	{
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	ListNode* ans = sln.reverseKGroup(head, 2);
	tmp = ans;
	while(tmp != NULL)
	{
		cout<<tmp->val<<"->";
		tmp = tmp->next;
	}
	cout<<endl;
	tmp = ans;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		delete ans;
		ans = tmp;
	}
	return 0;

}
