#ifndef  STACK
#define STACK
#include "Node.hpp"

class Stack
{
private:
	Node * _top;

public:
	Stack();
	~Stack();

	//AUX
	bool Is_empty();

	//PUSH AND POP
	void Push(int info);
	int Pop();

	//SEARCH
	int Search_in_pos(int pos);
	int Pos_of(int info);

};

#endif