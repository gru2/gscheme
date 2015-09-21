#include <GSObject.h>
#include <GSInteger.h>
#include <GSTypeTag.h>
#include <stdio.h>
#include <iostream>

void testGSObject()
{
	intitIntegerTypeTag();
	GSInteger i1(10);
	std::string i1s = i1.typeTag->toString(&i1);
	std::cout << "i1 = " << i1s << std::endl;
}

int main(int argc, char *argv[])
{
	printf("running GSObject test...\n");
	testGSObject();
	return 0;
}

