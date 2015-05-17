/*
 * =====================================================================================
 *
 *       Filename:  146_lru_cache.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/13/2015 06:55:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (Qi Liu), liuqi.edward@gmail.com
 *   Organization:  antq.com
 *
 * =====================================================================================
 */
#include<stdlib.h>
#include<unordered_map>
#include<list>
#include<utility>
#include<iostream>
using namespace std;
class LRUCache{
private:
	int _capacity;
	int _size;
	unordered_map<int, pair<list<int>::iterator, int> > _map;
	list<int> _list;

private:
	void update(list<int>::iterator& it){
		_list.push_front(*it);
		_list.erase(it);
	}
public:
    LRUCache(int capacity) {
		if(capacity > 0)
			_capacity = capacity;
		else
			_capacity = 1;
		_size = 0;
    }
    
    int get(int key) {
		auto it = _map.find(key);
		if(it == _map.end())
			return -1;
		update((it->second).first);
		_map[key] = make_pair(_list.begin(), (it->second).second);
		return (it->second).second;
    }
    
    void set(int key, int value) {
		auto it = _map.find(key);
		if(it != _map.end()){
			update((it->second).first);
		}else{
			if(_size == _capacity){
				list<int>::iterator kt = _list.end();
				kt--;
				_list.erase(kt);
				_map.erase(*kt);
			}else{
				_size++;
			}
			_list.push_front(key);
		}
		_map[key] = make_pair(_list.begin(), value);
    }
};

int main(){
	LRUCache cache(10);
	cache.set(2,1);
	cout<<cache.get(2)<<endl;
	cache.set(3,2);
	cout<<cache.get(2)<<endl;
	cout<<cache.get(3)<<endl;
	return 0;
}
