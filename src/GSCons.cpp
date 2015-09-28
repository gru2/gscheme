
#include <GSCons.h>
#include <GSTypeTag.h>
#include <assert.h>
#include <stdio.h>

int consCompare(GSObject *lhs, GSObject *rhs)
{
	assert(lhs->typeTag == &consTypeTag);
	assert(rhs->typeTag == &consTypeTag);
	GSCons *l = (GSCons *)lhs;
	GSCons *r = (GSCons *)rhs;
	// TODO
	return 0;
}

unsigned consHash(GSObject *x)
{
	assert(x->typeTag == &consTypeTag);
	GSCons *y = (GSCons *)x;
	unsigned carHash = y->car_->typeTag->hash(y->car_);
	unsigned cdrHash = y->cdr_->typeTag->hash(y->cdr_);
	return carHash + (cdrHash << 1);
}

std::string consToString(GSObject *x)
{
	assert(x->typeTag == &consTypeTag);
	GSCons *y = (GSCons *)x;
	std::string s = "(";
	s += y->car_->typeTag->toString(y->car_);
	s += ".";
	s += y->cdr_->typeTag->toString(y->cdr_);
	s += ")";
	return s;
}

GSTypeTag consTypeTag;

void initConsTypeTag()
{
	GSTypeTag &t = consTypeTag;
	t.typeName = "Cons";
	//t.mark = objectMark;
	//t.free = objectFree;
	t.compare = consCompare;
	t.hash = consHash;
	t.toString = consToString;
}

GSCons::GSCons() : GSObject(), car_(0), cdr_(0)
{
	typeTag = &consTypeTag;
}

GSCons::GSCons(GSObject *_car, GSObject *_cdr) : GSObject(),
	car_(_car), cdr_(_cdr)
{
	typeTag = &consTypeTag;
}

GSCons::~GSCons()
{
}

GSObject *car(GSObject *x)
{
}

GSObject *cdr(GSObject *x)
{
}
