/*
 * =====================================================================================
 *
 *       Filename:  224_basic_calculator.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/07/2015 09:52:48 PM
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
#include <string>
#include <stack>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
	struct node{
		bool numberic;
		int number;
	};
	int operate(int first, int second, char op){
		switch(op){
			case '+':
				return first + second;
			case '-':
				return first - second;
			case '*':
				return first * second;
			case '/':
				return first / second;
		}
		return 0;
	}
public:
    int calculate_bak(string s) {
		int first, second;
		string number;
		stack<int> number_stack;
		stack<char> op_stack;
		map<char, int> priority;
		priority['+'] = priority['-'] = 0;
		priority['*'] = priority['/'] = 1;
		priority['('] = priority[')'] = 2;
		int i = 0, size = s.size();
		char c, op;
		while( i != size ){
			c = s[i];
			if(c == ' '){
				i++;
				continue;
			}else if('0' <= c && c <= '9'){
				number = c;
				while('0' <= s[i+1] && s[i+1] <= '9'){
					i++;
					number += s[i];
				}
				number_stack.push(atoi(number.c_str()));
			}else if(c == ')'){
				op = op_stack.top();
				op_stack.pop();
				second = number_stack.top();
				number_stack.pop();
				while(op != '('){
					first = number_stack.top();
					number_stack.pop();
					second = operate(first, second, op);
					op = op_stack.top();
					op_stack.pop();
				}
				number_stack.push(second);
			}else{
				if(! op_stack.empty()){
					op = op_stack.top();
					while(op != '(' && priority[op] >= priority[c]){
						op_stack.pop();
						second = number_stack.top();
						number_stack.pop();
						first = number_stack.top();
						number_stack.pop();
						first = operate(first, second, op);
						number_stack.push(first);
						if(op_stack.empty()){
							break;
						}
						op = op_stack.top();
					}
				}
				op_stack.push(c);
			}
			i++;
		}
		second = number_stack.top();
		number_stack.pop();
		while(! number_stack.empty()){
			op = op_stack.top();
			op_stack.pop();
			first = number_stack.top();
			number_stack.pop();
			second = operate(first, second, op);
		}
		return second;
    }
    int calculate(string s) {
		map<char, int> priority;
		priority['+'] = priority['-'] = 0;
		priority['*'] = priority['/'] = 1;
		priority['('] = priority[')'] = 2;
		stack<char> op_stack;
		vector<node> nodes;
		int i = 0, size = s.size();
		string number;
		char c, op;
		while( i != size ){
			c = s[i];
			if(c == ' '){
				i++;
				continue;
			}else if('0' <= c && c <= '9'){
				number = c;
				while('0' <= s[i+1] && s[i+1] <= '9'){
					i++;
					number += s[i];
				}
				nodes.push_back(node{true, atoi(number.c_str())});
			}else if(c == ')'){
				op = op_stack.top();
				op_stack.pop();
				while(op != '('){
					nodes.push_back(node{false, op});
					op = op_stack.top();
					op_stack.pop();
				}
			}else{
				while(!op_stack.empty()){
					op = op_stack.top();
					if(op != '(' && priority[op] >= priority[c]){
						nodes.push_back(node{false, op});
						op_stack.pop();
					}else{
						break;
					}
				}
				op_stack.push(c);
			}
			i++;
		}
		while(!op_stack.empty()){
			op = op_stack.top();
			op_stack.pop();
			nodes.push_back(node{false, op});
		}
		stack<int> summary;
		int first, second;
		for(auto& i : nodes){
			if(i.numberic){
				summary.push(i.number);
			}else{
				second = summary.top();
				summary.pop();
				first = summary.top();
				summary.pop();
				summary.push(operate(first, second, i.number));
			}
		}
		return summary.top();
	}
};

int main(){
	string s = "(1+(4+5-2)*3)+(6+8)";
	Solution sln;
	cout<<sln.calculate(s)<<endl;
	return 0;
}
