/*
 * =====================================================================================
 *
 *       Filename:  155_min_stack.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/25/2015 11:29:42 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 *   Copyright (c) 2015, Qi Liu.
 *   All rights reserved.
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class MinStack {
private:
	int capacity;
	int size;
	vector<int> stack;
	vector<deque<int>> queues;
public:
	MinStack(){
		capacity = 0;
		size = 0;
	}
    void push(int x) {
		if(size < capacity) {
			stack[size] = x;
		}else {
			stack.push_back(x);
			capacity = stack.size();
		}
		if(queues.empty() || (!queues.back().empty() && x < stack[queues.back().back()])){
			queues.push_back(deque<int>());
		}
		deque<int>& qu = queues.back();
		while(!qu.empty() && qu.front() >= size) {
			qu.pop_front();
		}
		while(!qu.empty() && x < stack[qu.front()]){
			qu.pop_front();
		}
		qu.push_front(size);
		size++;
    }
    void pop() {
		size--;
		if(!queues.empty() && queues.back().back() >= size) {
			queues.pop_back();
		}
    }
    int top() {
		if(size > 0){
			return stack[size-1];
		}else{
			return 0;
		}
    }
    int getMin() {
		if(!queues.empty()){
			deque<int>& qu = queues.back();
			return stack[qu.back()];
		}else{
			return 0;
		}
    }
};

int main(){
	MinStack stack;
	stack.push(2);
	stack.push(0);
	stack.push(3);
	stack.push(0);
	cout<<stack.getMin()<<endl;
	stack.pop();
	cout<<stack.getMin()<<endl;
	stack.pop();
	cout<<stack.getMin()<<endl;
	stack.pop();
	cout<<stack.getMin()<<endl;
	return 0;
}
