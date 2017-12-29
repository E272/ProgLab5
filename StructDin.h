#include "MASSIVE.h"

struct Din
{
public:
	MASSIVE* info;
	int num;
	Din *next, *pred;
};

class LIST
{
	Din *Head;
	//Din * tmp;

public:
	int count;
	LIST();
	~LIST();
	Din * NewElem(MASSIVE * mas);
	void Addfront(MASSIVE* mas);
	void Addback(MASSIVE* mas);
	void Addpos(MASSIVE* mas, int _pos);
};

LIST::LIST()
{
	Head = NULL;
	count = 0;
	Head->num = count;
}

Din * LIST::NewElem(MASSIVE *mas)
{
	Din * netTemp = new Din;

	netTemp->info = mas;
	netTemp->next = NULL;
	netTemp->pred = NULL;

	return netTemp;
}

void LIST::Addfront(MASSIVE* mas)
{
	if (Head == NULL)
	{
		Head = NewElem(mas);
		Head->next = Head;
		Head->pred = Head;
		//count++;
	}
	else
	{
		Din * temp = Head->pred;

		Din * newE = NewElem(mas);
		newE->next = Head;
		newE->pred = temp;
		Head->pred = newE;
		temp->next = newE;

		Head = newE;
	}

	count++;
}

void LIST::Addback(MASSIVE* mas)
{

}

void LIST::Addpos(MASSIVE* mas, int _pos)
{

}

LIST::~LIST()
{

}