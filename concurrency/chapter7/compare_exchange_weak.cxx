#include <iostream>
#include <atomic>

class _node;

struct _node {
	_node(int i) : val_(i) {}
	int val_;
	_node *next;
};

int main(int, char **)
{

	std::atomic<_node *> head;
	head = nullptr;

	_node *new_node_1 = new _node{1};
	_node *new_node_2 = new _node{2};	
	// virtual thread A
	new_node_1->next = head.load();
	// virtual thread B 
	new_node_2->next = head.load();	
	// virtual thread A
	while (!head.compare_exchange_weak(new_node_1->next, new_node_1));
/*
	// test
	std::cout << head.load()->val_ << std::endl;	
	if (new_node_2->next)
		std::cout << new_node_2->next->val_ << std::endl;
*/
	// virtual thread B
	while (!head.compare_exchange_weak(new_node_2->next, new_node_2))
		std::cout << "Fail..." << std::endl;
/*
	if (new_node_2->next)
		std::cout << new_node_2->next->val_ << std::endl;
*/	
	_node *res_r = head.load();
	_node *res_l = res_r->next;
	std::cout << res_l->val_ << " " << res_r->val_ << std::endl;
	
	return 0;
}
