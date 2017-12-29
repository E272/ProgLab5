#include "queue.h"

int	Queue_massive::Get()
{
	int x;

	x = mas[0];
	 
	DEL(1);

	return x;
}

void Queue_massive::ADD(int x, int _pos)
{
	int* buf = mas;

	mas = new int[++maxsize];

	for (int i = 0; i < maxsize - 1; i++) { mas[i] = buf[i]; }

	
	delete[]buf;

	mas[maxsize - 1] = x;
}