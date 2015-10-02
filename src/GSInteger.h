#ifndef __GS_INTEGER_H
#define __GS_INTEGER_H

#include <GSObject.h>

extern GSTypeTag integerTypeTag;

void initIntegerTypeTag();

class GSInteger : public GSObject
{
public:
	GSInteger();
	GSInteger(int x);
	~GSInteger();

	int data;
};

int asInteger(GSObject *x);

#endif

