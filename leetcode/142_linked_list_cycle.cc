/*
 * =====================================================================================
 *
 *       Filename:  141_linked_list_cycle.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2015 07:36:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */


#include<stdint.h>
#include<unordered_map>
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
		if(head == NULL)
			return NULL;
		ListNode* first, *second;
		first = head;
		second = head;
		do{
			first = first->next;
			if(second->next != NULL)
				second = second->next->next;
			else
				return NULL;
		}while(second != NULL && first != second);
		if(second == NULL)
			return NULL;
		while(head != second){
			head = head->next;
			second = second->next;
		}
		return head;
	}
};

int main(){
	Solution sln;
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	cout<<sln.detectCycle(root)<<endl;
	return 0;
}
