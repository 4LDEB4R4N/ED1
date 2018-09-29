#ifndef NODE
#define NODE

class Node
{
private:
	int _info;
	Node * _next;

public:
	Node(int info);

	//SET
	void Set_info(int info);
	void Set_next(Node * next);

	//GET
	int Get_info();
	Node * Get_next();

};

class NodeDp
{
private:
	int _info;
	NodeDp * _next;
	NodeDp * _prev;

public:
	NodeDp(int info);

	//SET
	void Set_info(int info);
	void Set_next(NodeDp * next);
	void Set_prev(NodeDp * prev);

	//GET
	int Get_info();
	NodeDp * Get_next();
	NodeDp * Get_prev();

};

#endif