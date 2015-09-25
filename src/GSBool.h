#ifndef __GS_BOOL_H
#define __GS_BOOL_H

#include <GSObject.h>

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

#endif

