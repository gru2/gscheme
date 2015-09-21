#ifndef __GS_INTEGER_H
#define __GS_INTEGER_H

#include <GSObject.h>

class GSInteger : public GSObject
{
public:
	GSInteger();
	~GSInteger();
public:
	int data;
};

#endif

