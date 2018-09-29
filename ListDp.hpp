#ifndef LISTDP
#define LISTDP
#include "Node.hpp"

class ListDp
{
private:
	NodeDp * _bgn;

public:
	ListDp();
	~ListDp();

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