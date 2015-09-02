#ifndef __GS_OBJECT_H
#define __GS_OBJECT_H

class GSObject
{
public:
	GSObject();
	~GSObject();

protected:
	GSTypeTag *typeTag;
	unsigned flags;
	GSObject *next;
};

#endif
