#include <iostream>
#include "pageTableEntry.h"

using namespace std;

//constructor
PageTableEntry::PageTableEntry(){
	inMomery = false;
  frame = 30;
};

//get and sets for this class
int PageTableEntry::getFrame(){
  return frame;
};
bool PageTableEntry::in_Momery(){
  return inMomery;
};
void PageTableEntry::swapToDisk(int diskFrame){
  frame = diskFrame;
  inMomery = false;
};
void PageTableEntry::swapToMemory(int memFrame){
  frame = memFrame;
  inMomery = true;
};
