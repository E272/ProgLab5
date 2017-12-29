#include "cycle.h"

Cycle_massive::Cycle_massive(int size):MASSIVE(size)
{
	maxsize = size;
	pos = 0;
}

void Cycle_massive::SetSize(int size)
{
	maxsize = size;
	pos = 0;
}

void Cycle_massive::ADD(int x, int _pos)
{
	if (pos < maxsize)
		mas[pos++] = x;
	else
	{
		mas[0] = x;
		pos = 1;
	}
}