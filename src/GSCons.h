#ifndef __GSCONS_H
#define __GSCONS_H

#include <GSObject.h>

extern GSTypeTag consTypeTag;

void initConsTypeTag();

class GSCons : public GSObject
{
public:
	GSCons();
	GSCons(GSObject *_car, GSObject *_cdr);
	~GSCons();

	GSObject *car_;
	GSObject *cdr_;
};

GSObject *car(GSObject *x);
GSObject *cdr(GSObject *x);

#endif
