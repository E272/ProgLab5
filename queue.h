#include "MASSIVE.h"

class Queue_massive : public MASSIVE
{
public:
	int Get();

	void ADD(int x, int _pos) override;
};