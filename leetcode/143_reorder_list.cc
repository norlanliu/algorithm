/*
 * =====================================================================================
 *
 *       Filename:  143_reorder_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/29/2015 09:04:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

#include<stdlib.h>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
		if(head == NULL)
			return;
		int i, count, size;
		ListNode* tmp;
		vector<ListNode*> array;
		tmp = head;
		while(tmp != NULL){
			array.push_back(tmp);
			tmp = tmp->next;
		}
		if(array.size() < 3){
			return;
		}
		count = array.size() / 2;
		size = array.size() - 1;
		for(i = 0; i != count; ++i){
			tmp = array[size-i];
			tmp->next = head->next;
			head->next = tmp;
			head = tmp->next;
		}
		head->next = NULL;
    }
};

int main(){
	Solution sln;
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	sln.reorderList(root);
	return 0;
}
