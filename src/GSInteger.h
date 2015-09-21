#ifndef __GS_INTEGER_H
#define __GS_INTEGER_H

#include <GSObject.h>

extern GSTypeTag integerTypeTag;

void intitIntegerTypeTag();

class GSInteger : public GSObject
{
public:
	GSInteger();
	GSInteger(int x);
	~GSInteger();

	int data;
};

#endif

