#ifndef __GS_OBJECT_H
#define __GS_OBJECT_H

class GSTypeTag;

class GSObject
{
public:
	GSObject();
	~GSObject();

	GSTypeTag *typeTag;
	unsigned flags;
	GSObject *next;
};

#endif
