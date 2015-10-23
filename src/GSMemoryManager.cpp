#include <GSMemoryManager.h>
#include <GSObject.h>
#include <stdlib.h>
#include <assert.h>

GSMemoryManager::GSMemoryManager()
{
}

GSMemoryManager::~GSMemoryManager()
{
}

GSObject *GSMemoryManager::allocateObject(int size, GSTypeTag *tt)
{
	assert(size >= sizeof(GSObject));
	GSObject *r = (GSObject *)malloc(size);
	r->typeTag = tt;
	return r;
}

void GSMemoryManager::collectGarbage()
{
}

