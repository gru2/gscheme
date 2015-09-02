
#include <GSTypeTag.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void fail()
{
	cout << "TEST_FAILED\n";
	exit(1);
}

void test_GSTypeTag()
{
	GSTypeTag x;
	cout << "TEST_PASSED\n";
}

int main(int argc, char *argv[])
{
	test_GSTypeTag();
	return 0;
}
