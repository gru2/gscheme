#ifndef __GS_INTEGER_H
#define __GS_INTEGER_H

#include <GSObject.h>

class GSMemoryManager;

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
GSObject *createInteger(int x, GSMemoryManager *mm);

#endif

