/*
 * =====================================================================================
 *
 *       Filename:  61_rotate_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/27/2015 08:53:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(k == 0 || head == NULL)
			return head;
		int i, n;
		ListNode* new_head, * k_head;
		new_head = head;
		for(n = 0; new_head != NULL; ++n){
			new_head = new_head->next;
		}
		new_head = head;
		k %= n;
		n = n - k - 1;
		for(i = 0; i < n && new_head != NULL; ++i){
			new_head = new_head->next;
		}
		if(new_head == NULL || new_head->next == NULL)
			return head;
		else{
			k_head = new_head->next;
			new_head->next = NULL;
			new_head = k_head;
			while(new_head->next != NULL)
				new_head = new_head->next;
			new_head->next = head;
		}
		return k_head;
    }
};

int main(){
	Solution sln;
	ListNode* head = new ListNode(0);
	ListNode* tmp = head;
	for(int i = 1; i < 6; ++i){
		tmp->next = new ListNode(i);
		tmp = tmp->next;
	}
	ListNode* ans = sln.rotateRight(head, 6);
	tmp = ans;
	while(tmp != NULL){
		cout<<tmp->val<<"->";
		ans = ans->next;
		delete tmp;
		tmp = ans;
	}
	cout<<endl;
	return 0;
}
