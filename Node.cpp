#include <iostream>
#include "Node.hpp"
using namespace std;

//NODE

	Node :: Node(int info):

		_info(info),
		_next(NULL)

	{}

	void Node :: Set_info(int info)
	{
		_info = info;
	}

	void Node :: Set_next(Node * next) 
	{
		_next = next;
	}

	int Node :: Get_info()
	{
		return _info;
	}

	Node * Node :: Get_next()
	{
		return _next;
	}

//NODEDP

	NodeDp :: NodeDp(int info):

		_info(info),
		_next(NULL),
		_prev(NULL)

	{}

	void NodeDp :: Set_info(int info)
	{
		_info = info;
	}

	void NodeDp :: Set_next(NodeDp * next) 
	{
		_next = next;
	}

	void NodeDp :: Set_prev(NodeDp * prev)
	{
		_prev = prev;
	}

	int NodeDp :: Get_info()
	{
		return _info;
	}

	NodeDp * NodeDp :: Get_next()
	{
		return _next;
	}

	NodeDp * NodeDp :: Get_prev()
	{
		return _prev;
	}
