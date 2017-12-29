#include "MASSIVE.h"

class Cycle_massive : public MASSIVE
{
private:
	int pos;

public:
	Cycle_massive(int size);

	void SetSize(int size);

	void ADD (int x, int _pos) override;
};