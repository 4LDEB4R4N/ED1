#include <iostream>
#include "Queue.hpp"
using namespace std;

//QUEUE

Queue :: Queue():
	
	_first(NULL),
	_last(NULL)

{}

Queue :: ~Queue()
{
	while(not Is_empty()) Remove();
}

//AUX

bool Queue :: Is_empty()
{
	if(_first == NULL) return true;

	else return false;
}

//INSERT AND REMOVE

void Queue :: Insert(int info)
{
	Node * neo = new Node(info);

	if(Is_empty()){

		_first = neo;
		_last = neo;

	}
	else{

		_last->Set_next(neo);
		_last = neo;

	}
}

int Queue :: Remove()
{
	Node * to_delete;
	int to_return;

	if(Is_empty()){

		cout << endl << "Removal ERROR !!\nThe queue is empty" << endl << endl;

		return 0;
		
	}
	else{

		to_return = _first->Get_info();
		to_delete = _first;
		_first = _first->Get_next();
		delete to_delete;
		return to_return;

	}
}

//SEARCH

int Queue :: Search_in_pos(int pos)
{
	Queue aux;
	int i;
	int to_return;

	if(pos <= 0){

		cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

		return 0;

	}

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe queue is empty" << endl << endl;

		return 0;

	}

	for(i = 1; i != pos and not Is_empty(); ++i, aux.Insert(Remove()));

	if(not Is_empty()){

		to_return = Remove();
		aux.Insert(to_return);

	}
	else{

		cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

		to_return = 0;

	}

	while(not Is_empty()) aux.Insert(Remove());

	while(not aux.Is_empty()) Insert(aux.Remove());

	return to_return;
}

int Queue :: Pos_of(int info)
{
	Queue aux;
	int pos, i;

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe queue is empty" << endl << endl;

		return 0;

	}

	for(pos = 1; not Is_empty(); ++pos){

		i = Remove();
		aux.Insert(i);

		if(i == info) break;

	}

	if(i != info){

		cout << endl << "Search ERROR !!\nThe information is not in the queue : info " << info << endl << endl;

		pos = 0;

	}

	while(not Is_empty()) aux.Insert(Remove());

	while(not aux.Is_empty()) Insert(aux.Remove());

	return pos;

}