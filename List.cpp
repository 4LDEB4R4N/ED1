#include <iostream>
#include "List.hpp"
using namespace std;

//LIST
	
List :: List():

	_bgn(NULL)

{}

List :: ~List()
{
	while (not Is_empty()) Remove_bgn();
}

//AUX

bool List :: Is_empty()
{
	if(_bgn == NULL) return true;

	else return false;
}

//INSERT

void List :: Insert_bgn(int info)
{
	Node * neo = new Node(info);

	neo->Set_next(_bgn);
	_bgn = neo;
}

void List :: Insert_end(int info)
{
	Node * neo = new Node(info);
	Node * aux;

	if(Is_empty()) _bgn = neo;

	else{

		for(aux = _bgn; aux->Get_next() != NULL; aux = aux->Get_next());

		aux->Set_next(neo);

	}
}

void List :: Insert_in_pos(int info, int pos)
{
	Node * neo = new Node(info);
	Node * aux;
	int i;

	if(pos <= 0) cout << endl << "Insertion ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	else if(pos == 1) Insert_bgn(info);

	else{

		for(aux = _bgn, i = 1; aux != NULL and i != pos-1; aux = aux->Get_next(), ++i);

		if(aux != NULL){

			neo->Set_next(aux->Get_next());
			aux->Set_next(neo);

		}
		else cout << endl << "Insertion ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	}
}

//REMOVE

void List :: Remove_bgn()
{
	Node * To_delete;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else{

		To_delete = _bgn;
		_bgn = _bgn->Get_next();
		delete To_delete;

	}
}

void List :: Remove_end()
{
	Node * To_delete;
	Node * aux;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else if(_bgn->Get_next() == NULL) Remove_bgn();

	else{

		for(aux = _bgn; aux->Get_next()->Get_next() != NULL; aux = aux->Get_next());

		To_delete = aux->Get_next();
		aux->Set_next(NULL);
		delete To_delete;

	}
}

void List :: Remove_in_pos(int pos)
{
	Node * To_delete;
	Node * aux;
	int i;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else if(pos == 1) Remove_bgn();

	else{

		for(aux = _bgn, i = 1; aux->Get_next() != NULL and i != pos-1; aux = aux->Get_next(), ++i);

		if(aux->Get_next() != NULL){

			To_delete = aux->Get_next();
			aux->Set_next(To_delete->Get_next());
			delete To_delete;

		}
		else cout << endl << "Removal ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	}
}

//SEARCH

int List :: Search_in_pos(int pos)
{
	Node * aux;
	int i;

	if(pos <= 0){

		cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

		return 0;

	}

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe list is empty" << endl << endl;

		return 0;

	}
	else{

		for(aux = _bgn, i = 1; aux != NULL and i != pos; aux = aux->Get_next(), ++i);

		if(aux != NULL){

			return aux->Get_info();

		}
		else{

			cout << endl << "Search ERROR !!\nInaccessible position : pos " << pos << endl << endl;

			return 0;

		}
	}
}

int List :: Pos_of(int info)
{
	Node * aux;
	int i;

	if(Is_empty()){

		cout << endl << "Search ERROR !!\nThe list is empty" << endl << endl;

		return 0;
		
	}
	else{

		for(aux = _bgn, i = 1; aux != NULL and aux->Get_info() != info; aux = aux->Get_next(), ++i);

		if(aux != NULL){

			return i;

		}
		else{

			cout << endl << "Search ERROR !!\nThe information is not in the list : info " << info << endl << endl;

			return 0;

		} 
	}
}

//SHOW

void List :: Show()
{
	Node * aux;

	if(Is_empty()) cout << endl << "The list is empty, nothing to show" << endl << endl;

	else {

		cout << "Showing the list:" << endl;

		for(aux = _bgn; aux != NULL; aux = aux->Get_next()){

			cout << aux->Get_info() << endl;

		}

		cout << "-----------------" << endl;

	}
}

