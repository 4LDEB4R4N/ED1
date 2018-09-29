#include <iostream>
#include "Stack.hpp"
using namespace std;

//STACK

Stack :: Stack():

	_top(NULL)

{}

Stack :: ~Stack()
{
	while(not Is_empty()) Pop();
}

//AUX

bool Stack :: Is_empty()
{
	if(_top == NULL) return true;

	else return false;
}

//PUSH AND POP

void Stack :: Push(int info)
{
	Node * neo = new Node(info);

	neo->Set_next(_top);
	_top = neo;
}

int Stack :: Pop()
{
	Node * to_delete;
	int to_return;

	if(Is_empty()){

		cout << endl << "Removal ERROR !!\nThe stack is empty" << endl << endl;

		return 0;
		
	}
	else{

		to_delete = _top;
		to_return = _top->Get_info();
		_top = _top->Get_next();
		delete to_delete;
		return to_return;	

	}
}

//SEARCH

int Stack :: Search_in_pos(int pos)
{	
	Stack aux;
	int i;
	int to_return;

	if(pos <= 0){

		cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

		return 0;

	}

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe stack is empty" << endl << endl;

		return 0;

	}

	for(i = 1; i != pos and not Is_empty(); ++i, aux.Push(Pop()));

	if(i == pos){

		to_return = Pop();
		Push(to_return);

	}
	else {

		cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

		to_return = 0;

	}

	while(not aux.Is_empty()) Push(aux.Pop());

	return to_return;
}

int Stack :: Pos_of(int info)
{
	Stack aux;
	int pos, i;

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe stack is empty" << endl << endl;

		return 0;

	}

	for(pos = 1; not Is_empty(); ++pos, aux.Push(i)){

		i = Pop();

		if(i == info){

			Push(i);
			break;

		}

	}

	if(i != info){

		cout << endl << "Search ERROR !!\nThe information is not in the stack : info " << info << endl << endl;

		pos = 0;

	}

	while(not aux.Is_empty()) Push(aux.Pop());

	return pos;
}