#include <GSInteger.h>
#include <GSTypeTag.h>
#include <assert.h>
#include <stdio.h>

int integerCompare(GSObject *lhs, GSObject *rhs)
{
	assert(lhs->typeTag == &integerTypeTag);
	assert(rhs->typeTag == &integerTypeTag);
	GSInteger *l = (GSInteger *)lhs;
	GSInteger *r = (GSInteger *)rhs;
	if (l->data < r->data)
		return -1;
	if (l->data > r->data)
		return 1;
	return 0;
}

unsigned integerHash(GSObject *x)
{
	assert(x->typeTag == &integerTypeTag);
	GSInteger *y = (GSInteger *)x;
	return (unsigned)y->data;
}

std::string integerToString(GSObject *x)
{
	assert(x->typeTag == &integerTypeTag);
	GSInteger *y = (GSInteger *)x;
	char buff[128];
	sprintf(buff, "%d", y->data);
	return buff;
}

GSTypeTag integerTypeTag;

void initIntegerTypeTag()
{
	GSTypeTag &t = integerTypeTag;
	t.typeName = "Integer";
	//t.mark = objectMark;
	//t.free = objectFree;
	t.compare = integerCompare;
	t.hash = integerHash;
	t.toString = integerToString;
}

GSInteger::GSInteger() : GSObject(), data(0)
{
	typeTag = &integerTypeTag;
}

GSInteger::GSInteger(int x) : GSObject(), data(x)
{
	typeTag = &integerTypeTag;
}

GSInteger::~GSInteger()
{
}

int asInteger(GSObject *x)
{
	assert(x->typeTag == &integerTypeTag);
	GSInteger *y = (GSInteger *)x;
	return y->data;
}

