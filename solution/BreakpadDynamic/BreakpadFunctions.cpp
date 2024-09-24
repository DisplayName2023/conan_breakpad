#include "BreakpadFunctions.h"

void InitializeBreakpad();

extern "C"
{

	void initBreakpad()
	{
		InitializeBreakpad();
	}

}
