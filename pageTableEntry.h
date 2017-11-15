
#ifndef PAGETABLEENTRY_H
#define PAGETABLEENTRY_H

#include <iostream>
#include "pageTableEntry.h"

using namespace std;

class PageTableEntry{
	//var
	private:
		bool inMomery;
    int frame;

	//methods and constructor
	public:
		PageTableEntry();
    int getFrame();
    bool in_Momery();
    void swapToDisk(int diskFrame);
		void swapToMemory(int memFrame);
};
#endif
