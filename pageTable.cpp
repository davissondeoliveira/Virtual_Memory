#include <iostream>
#include "pageTable.h"
#include "pageTableEntry.h"

using namespace std;

//constructor
PageTable::PageTable(){
	//??
};

//get and sets for this class
void PageTable::setPTE(int pt, PageTableEntry* pte){
  entries[pt] = pte;
};
PageTableEntry* PageTable::getPTE(int page){
  return entries[page];
};
