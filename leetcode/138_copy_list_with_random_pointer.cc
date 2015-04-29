/*
 * =====================================================================================
 *
 *       Filename:  138_copy_list_with_random_pointer.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/2015 09:13:02 PM
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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if(head == NULL)
			return NULL;
		RandomListNode ans(0), * ans_tmp, *head_tmp;
		unordered_map<RandomListNode*, RandomListNode*> head_map;
		head_tmp = head;
		ans_tmp = &ans;
		while(head_tmp != NULL){
			ans_tmp->next = new RandomListNode(head_tmp->label);
			ans_tmp = ans_tmp->next;
			head_map[head_tmp] = ans_tmp; 
			head_tmp = head_tmp->next;
		}
		head_tmp = head;
		ans_tmp = ans.next;
		while(head_tmp != NULL){
			if(head_tmp->random != NULL){
				ans_tmp->random = head_map[head_tmp->random];
			}
			ans_tmp = ans_tmp->next;
			head_tmp = head_tmp->next;
		}
		return ans.next;
    }
};
