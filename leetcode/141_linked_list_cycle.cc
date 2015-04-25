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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> is_visited;
		while(head != NULL){
			if(is_visited.find(head->next) != is_visited.end()){
				return true;
			}
			is_visited[head] = true;
			head = head->next;
		}
		return false;
    }
};

int main(){
	Solution sln;
	ListNode* root = new ListNode(1);
	root->next = new ListNode(2);
	cout<<sln.hasCycle(root)<<endl;
	return 0;
}
