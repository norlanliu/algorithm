/*
 * =====================================================================================
 *
 *       Filename:  83_remove_duplicates_from_list.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/03/2015 10:16:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* cur, *old, *tail;
        cur = head;
        tail = head->next;
        while(tail != NULL){
            if(tail->val == cur->val){
                old = tail;
                tail = tail->next;
                delete old;
            }else{
                cur->next = tail;
                cur = tail;
                tail = tail->next;
            }
        }
        cur->next = NULL;
        return head;
    }
};
