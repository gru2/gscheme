#include <GSBool.h>
#include <GSTypeTag.h>
#include <assert.h>
#include <stdio.h>

int boolCompare(GSObject *lhs, GSObject *rhs)
{
	assert(lhs->typeTag == &boolTypeTag);
	assert(rhs->typeTag == &boolTypeTag);
	GSBool *l = (GSBool *)lhs;
	GSBool *r = (GSBool *)rhs;
	if (l->data && r->data)
		return 0;
	if (!l->data && !r->data)
		return 0;
	if (!l->data && r->data)
		return -1;
	if (l->data && !r->data)
		return 1;
	return 0;
}

unsigned boolHash(GSObject *x)
{
	assert(x->typeTag == &boolTypeTag);
	GSBool *y = (GSBool *)x;
	return (unsigned)!y->data;
}

std::string boolToString(GSObject *x)
{
	assert(x->typeTag == &boolTypeTag);
	GSBool *y = (GSBool *)x;
	if (y->data)
		return "true";
	return "false";
}

GSTypeTag boolTypeTag;

void initBoolTypeTag()
{
	GSTypeTag &t = boolTypeTag;
	t.typeName = "Bool";
	//t.mark = objectMark;
	//t.free = objectFree;
	t.compare = boolCompare;
	t.hash = boolHash;
	t.toString = boolToString;
}

GSBool::GSBool() : GSObject(), data(false)
{
	typeTag = &boolTypeTag;
}

GSBool::GSBool(bool x) : GSObject(), data(x)
{
	typeTag = &boolTypeTag;
}

GSBool::~GSBool()
{
}

bool asBool(GSObject *x)
{
	assert(x->typeTag == &boolTypeTag);
	GSBool *y = (GSBool *)x;
	return y->data;
}

