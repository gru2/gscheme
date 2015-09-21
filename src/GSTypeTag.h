#ifndef __GSTYPETAG_H
#define __GSTYPETAG_H

#include <string>

class GSObject;
class GSMemoryManager;

class GSTypeTag
{
public:
	GSTypeTag();
	~GSTypeTag();

	std::string typeName;
	void (*mark)(GSObject *x, GSMemoryManager *mm);
	void (*free)(GSObject *x, GSMemoryManager *mm);
	int (*compare)(GSObject *lhs, GSObject *rhs);
	unsigned (*hash)(GSObject *x);
	std::string (*toString)(GSObject *x);
};

#endif
