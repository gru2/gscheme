#include <GSMemoryManager.h>
#include <stdlib.h>

GSMemoryManager::GSMemoryManager()
{
}

GSMemoryManager::~GSMemoryManager()
{
}

void *GSMemoryManager::allocateObject(int size)
{
	return malloc(size);
}

void GSMemoryManager::collectGarbage()
{
}

