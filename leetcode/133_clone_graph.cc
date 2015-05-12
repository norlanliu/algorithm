/*
 * =====================================================================================
 *
 *       Filename:  133_clone_graph.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2015 09:10:20 AM
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
#include<stack>
#include<unordered_map>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
	void dfs(UndirectedGraphNode* node, UndirectedGraphNode* cur_node){
		UndirectedGraphNode *new_node;
		for(auto& it : node->neighbors){
			auto iter = map.find(it);
			if(iter == map.end()){
				new_node = new UndirectedGraphNode(it->label);
				map[it] = new_node;
				cur_node->neighbors.push_back(new_node);
				dfs(it, new_node);
			}else{
				cur_node->neighbors.push_back(iter->second);
			}
		}

	}
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
			return NULL;
		UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
		map[node] = head;
		dfs(node, head);
		return head;
	}
    UndirectedGraphNode *cloneGraph_old(UndirectedGraphNode *node) {
        if(node == NULL)
			return NULL;
		UndirectedGraphNode* tmp, *new_node, *cur_node;
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
		stack<UndirectedGraphNode*> s;
		UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
		map[node] = head;
		s.push(node);
		while(!s.empty()){
			tmp = s.top();
			s.pop();
			cur_node = map[tmp];
			for(auto& it : tmp->neighbors){
				auto iter = map.find(it);
				if(iter == map.end()){
					new_node = new UndirectedGraphNode(it->label);
					map[it] = new_node;
					cur_node->neighbors.push_back(new_node);
					s.push(it);
				}else{
					cur_node->neighbors.push_back(iter->second);
				}
			}
		}
		return head;
    }
};
