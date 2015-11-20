
#include <GSchemeObject.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void fail()
{
	cout << "TEST_FAILED\n";
	exit(1);
}

void test_GSchemeObject()
{
	GSchemeObject x;
	cout << "TEST_PASSED\n";
}

int main(int argc, char *argv[])
{
	test_GSchemeObject();
	return 0;
}
