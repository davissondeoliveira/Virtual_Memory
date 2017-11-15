
#ifndef PROCESSTABLE_H
#define PROCESSTABLE_H

#include <iostream>
#include "processTable.h"
#include "pageTable.h"

using namespace std;

class ProcessTable{
	//var
	private:
		PageTable* procPageTable[30];
    int frame;

	//methods and constructor
	public:
		ProcessTable();
    void setProcPT(int pid, PageTable* pt);
    PageTable* getProcPT(int pid);
};
#endif
