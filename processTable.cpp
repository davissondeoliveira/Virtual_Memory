#include <iostream>
#include "processTable.h"
#include "pageTable.h"

using namespace std;

//constructor
ProcessTable::ProcessTable(){
	//??
};
//get and sets for this class
void ProcessTable::setProcPT(int pid, PageTable* pt){
  procPageTable[pid] = pt;
};
PageTable* ProcessTable::getProcPT(int pid){
  return procPageTable[pid];
};
