#ifndef __GS_BOOL_H
#define __GS_BOOL_H

#include <GSObject.h>

class GSMemoryManager;

extern GSTypeTag boolTypeTag;

void initBoolTypeTag();

class GSBool : public GSObject
{
public:
	GSBool();
	GSBool(bool x);
	~GSBool();

	bool data;
};

bool asBool(GSObject *x);
GSObject *createBool(bool x, GSMemoryManager *mm);

#endif

