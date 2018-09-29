#ifndef QUEUE
#define QUEUE
#include "Node.hpp"

class Queue
{
private:
	Node * _first;
	Node * _last;

public:
	Queue();
	~Queue();

	//AUX
	bool Is_empty();

	//INSERT AND REMOVE
	void Insert(int info);
	int Remove();

	//SEARCH
	int Search_in_pos(int pos);
	int Pos_of(int info);
	
};

#endif