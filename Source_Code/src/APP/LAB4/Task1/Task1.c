#include "APP/CTRMain.h"
#ifdef LAB4_TASK1
#include "HAL/SevenSegment.h"
int main (void)
{
	SevenSegment_enumInit ();
	while(1)
	{

		SevenSegment_enumSetValueForAll(22);
	}
}
#endif