#ifndef __GS_MEMORY_MANAGER_H
#define __GS_MEMORY_MANAGER_H

class GSObject;
class GSTypeTag;

class GSMemoryManager
{
public:
	GSMemoryManager();
	~GSMemoryManager();

	void collectGarbage();
	GSObject *allocateObject(int size, GSTypeTag *tt);
protected:
	GSObject *allocatedObjects;
	GSObject *liveObjects;
};

#endif

