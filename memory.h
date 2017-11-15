
#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include "memory.h"
#include "pageTableEntry.h"

using namespace std;

class Memory{
	//var
	private:
		PageTableEntry* frames[30];
		int pointer;

	//methods and constructor
	public:
    Memory();
    void setFrame(int frame, PageTableEntry* pte);
    int getFreeFrame();
		int getCurrent();
};
#endif
