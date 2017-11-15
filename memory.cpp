#include <iostream>
#include "memory.h"
#include "pageTableEntry.h"

using namespace std;

//constructor
Memory::Memory(){
	pointer = 0;
};

//get and sets for this class
void Memory::setFrame(int frame, PageTableEntry* pte){
	frames[frame] = pte;
};

int Memory::getCurrent(){
  return pointer;
}

int Memory::getFreeFrame(){
  int n = 0;
  if(frames[pointer] != NULL){
    frames[pointer] -> swapToDisk(-1);
    //frames[pointer] = NULL;
  }
  n = pointer;
  pointer = (pointer + 1) % 30;
  return n;
};
