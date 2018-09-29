#include <iostream>
#include "ListDp.hpp"
using namespace std;

//LISTDP
	
ListDp :: ListDp():

	_bgn(NULL)

{}

ListDp :: ~ListDp()
{
	while(not Is_empty()) Remove_bgn();
}

//AUX

bool ListDp :: Is_empty()
{
	if (_bgn == NULL) return true;

	else return false;
}

//INSERT

void ListDp :: Insert_bgn(int info)
{
	NodeDp * neo = new NodeDp(info);

	if(Is_empty()) _bgn = neo;

	else{

		_bgn->Set_prev(neo);
		neo->Set_next(_bgn);
		_bgn = neo;

	}
}

void ListDp :: Insert_end(int info)
{
	NodeDp * neo = new NodeDp(info);
	NodeDp * aux;

	if(Is_empty()) _bgn = neo;

	else{

		for(aux = _bgn; aux->Get_next() != NULL; aux = aux->Get_next());

		neo->Set_prev(aux);
		aux->Set_next(neo);

	}
}

void ListDp :: Insert_in_pos(int info, int pos)
{
	NodeDp * neo = new NodeDp(info);
	NodeDp * aux;
	int i;

	if(pos <= 0) cout << endl << "Insertion ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	else if(pos == 1) Insert_bgn(info);

	else{

		for(aux = _bgn, i = 1; aux != NULL and i != pos-1; aux = aux->Get_next(), ++i);

		if(aux != NULL){

			if(aux->Get_next() != NULL) aux->Get_next()->Set_prev(neo);
			neo->Set_next(aux->Get_next());
			aux->Set_next(neo);
			neo->Set_prev(aux);

		}
		else cout << endl << "Insertion ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	}
}

//REMOVE

void ListDp :: Remove_bgn()
{
	NodeDp * To_delete;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else{

		To_delete = _bgn;
		_bgn = _bgn->Get_next();
		if(not Is_empty())_bgn->Set_prev(NULL);
		delete To_delete;

	}
}

void ListDp :: Remove_end()
{
	NodeDp * To_delete;
	NodeDp * aux;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else if(_bgn->Get_next() == NULL) Remove_bgn();

	else{

		for(aux = _bgn; aux->Get_next() != NULL; aux = aux->Get_next());

		To_delete = aux;
		aux->Get_prev()->Set_next(NULL);
		delete To_delete;

	}
}

void ListDp :: Remove_in_pos(int pos)
{
	NodeDp * To_delete;
	NodeDp * aux;
	int i;

	if(Is_empty()) cout << endl << "Removal ERROR !!\nThe list is empty" << endl << endl;

	else if(pos == 1) Remove_bgn();

	else{

		for(aux = _bgn, i = 1; aux != NULL and i != pos; aux = aux->Get_next(), ++i);

		if(aux != NULL){

			To_delete = aux;
			if(aux->Get_next() != NULL) aux->Get_next()->Set_prev(aux->Get_prev());
			aux->Get_prev()->Set_next(aux->Get_next());
			delete To_delete;

		}
		else cout << endl << "Removal ERROR !!\nInaccessible position : pos " << pos << endl << endl;

	}
}

//SEARCH

int ListDp :: Search_in_pos(int pos)
{
	NodeDp * aux;
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

int ListDp :: Pos_of(int info)
{
	NodeDp * aux;
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

void ListDp :: Show()
{
	NodeDp * aux;

	if(Is_empty()) cout << endl << "The list is empty, nothing to show" << endl << endl;

	else {

		cout << "Showing the list:" << endl;

		for(aux = _bgn; aux != NULL; aux = aux->Get_next()){

			cout << aux->Get_info() << endl;

		}

		cout << "-----------------" << endl;

	}
}
