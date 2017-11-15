
#ifndef PAGETABLE_H
#define PAGETABLE_H

#include <iostream>
#include "pageTable.h"
#include "pageTableEntry.h"

using namespace std;

class PageTable{
	//var
	private:
		PageTableEntry* entries[64];

	//methods and constructor
	public:
		PageTable();
		void setPTE(int pt, PageTableEntry* pte);
		PageTableEntry* getPTE(int page);
};
#endif
