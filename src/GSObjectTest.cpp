#include <GSObject.h>
#include <GSInteger.h>
#include <GSBool.h>
#include <GSTypeTag.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void fail()
{
	printf ("FAILED\n");
	exit(1);
}

void testGSObject()
{
	initIntegerTypeTag();
	initBoolTypeTag();

	const int ivr = 10;
	GSInteger i1(ivr);
	std::string i1s = i1.typeTag->toString(&i1);
	std::cout << "i1 = " << i1s << std::endl;
	int iv = asInteger(&i1);
	if (iv != ivr)
		fail();
	const bool bvr = true;
	GSBool b1(bvr);
	std::string b1s = b1.typeTag->toString(&b1);
	std::cout << "b1 = " << b1s << std::endl;
	bool bv = asBool(&b1);
	if (bv != bvr)
		fail();
}

int main(int argc, char *argv[])
{
	printf("running GSObject test...\n");
	testGSObject();
	printf("PASSED\n");
	return 0;
}

