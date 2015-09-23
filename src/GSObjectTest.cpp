#include <GSObject.h>
#include <GSInteger.h>
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
	intitIntegerTypeTag();
	const int vr = 10;
	GSInteger i1(vr);
	std::string i1s = i1.typeTag->toString(&i1);
	std::cout << "i1 = " << i1s << std::endl;
	int v = getInteger(&i1);
	if (v != vr)
		fail();
}

int main(int argc, char *argv[])
{
	printf("running GSObject test...\n");
	testGSObject();
	printf("PASSED\n");
	return 0;
}

