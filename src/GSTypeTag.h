#ifndef __GSTYPETAG_H
#define __GSTYPETAG_H

#include <string>

class GSTypeTag
{
public:
	GSTypeTag();
	~GSTypeTag();

protected:
	std::string typeName;
	void (*mark)(GSObject *x);
	void (*free)(GSObject *x);
	int (*compare)(GSObject *x);
	unsigned (*hash)(GSObject *x);
	std::string (*toString)(GSObject *x);
};

#endif
