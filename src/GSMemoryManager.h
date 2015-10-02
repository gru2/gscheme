#ifndef __GS_MEMORY_MANAGER_H
#define __GS_MEMORY_MANAGER_H

class GSObject;

class GSMemoryManager
{
public:
	GSMemoryManager();
	~GSMemoryManager();

	void collectGarbage();
	void *allocateObject(int size);
protected:
	GSObject *allocatedObjects;
	GSObject *liveObjects;
};

#endif

