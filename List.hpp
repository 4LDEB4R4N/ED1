#ifndef LIST
#define LIST
#include "Node.hpp"

class List
{
private:
	Node * _bgn;

public:
	List();
	~List();

	//AUX
	bool Is_empty();

	//INSERT
	void Insert_bgn(int info);
	void Insert_end(int info);
	void Insert_in_pos(int info, int pos);

	//REMOVE
	void Remove_bgn();
	void Remove_end();
	void Remove_in_pos(int pos);

	//SEARCH
	int Search_in_pos(int pos);
	int Pos_of(int info);

	//SHOW
	void Show();

};

#endif